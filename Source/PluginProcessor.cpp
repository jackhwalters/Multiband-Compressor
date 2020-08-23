/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

CompressorAudioProcessor::CompressorAudioProcessor()
    // Buffers initialised through inline implementation
    :
    inputBuffer(1,1),
    processBuffer(1,1),
    monoBuffer(1,1)
{
    numberOfCompressors = 4;
    lastPosInfo.resetToDefault();   // Last audio playhead position set to default
}

CompressorAudioProcessor::~CompressorAudioProcessor() {}

//==============================================================================
void CompressorAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback initialisation that you need.
    M = round(getNumInputChannels());   // Set M to number of input channels
    samplerate = (float)getSampleRate();    // Initialise samplerate variable to be used in other methods
    bufferSize = getBlockSize();    // Initialise buffer size variable to be used in other methods
    // Allocate dynamic memory here to be used in the ::compressor method
    x_g                    .allocate(bufferSize, true);
    x_l                    .allocate(bufferSize, true);
    y_g                    .allocate(bufferSize, true);
    y_l                    .allocate(bufferSize, true);
    c                    .allocate(bufferSize, true);
    *yL_prev=0;
    autoTime = false;
    compressorONOFF = false;
    resetAll();
}

void CompressorAudioProcessor::releaseResources()
{
    // When playback stops, you can use this to free up any spare memory, etc.
}

void CompressorAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)

{
    if (compressorONOFF)
    {
        // set channel variable to total number of input channels and set inputBuffer to buffer, then clear buffer
        int channels = getTotalNumInputChannels();
        inputBuffer.setSize(channels,bufferSize);
        inputBuffer = buffer;
        processBuffer.setSize(channels,bufferSize);
        buffer.clear();

        // Iterate through the channels
        for (int channel = 0 ; channel < channels ; channel++)
        {
            // Clear process buffer every iteration of this channel for loop
            processBuffer.clear();

            // Iterate through the compressors assigned to each band
            for (int i = 0; i < numberOfCompressors-1; i++)
            {
                // Create a copy of each channel for every compressor
                processBuffer.copyFrom(channel, 0, inputBuffer, channel, 0, bufferSize);

                // Assign a pointer to whichever channel of process buffer the channel for loop is processing at that time
                float* ChannelData = processBuffer.getWritePointer(channel);

                // Pass the channel data at compressor index i through the crossover function
                crossover(ChannelData, i, channel);

                // Pass the channel data at compressor index i through the compress function
                compress(processBuffer, i);

                // Add the channel data from process buffer back to the original buffer
                buffer.addFrom(channel, 0, processBuffer, channel, 0, bufferSize);
            }
        }
    }
}

void CompressorAudioProcessor::crossover(float* channelData, int filterType, int filterIndex)
{
    //     Low-pass
    if (filterType == 0)
    {

        // Filters are indexed so that an individual filter is being used at every crossover point in the method structure
        IIRFilLP[filterIndex] // First the coefficients are set
        .setCoefficients(IIRCoeff.makeLowPass(samplerate, crossoverPoint1, passQ));
        IIRFilLP[filterIndex] // Then the initialised filter processed the samples in the buffer
        .processSamples(channelData, bufferSize);
    
    }
    
    // High-pass
    else if (filterType == 1)
    {

        IIRFilHP[filterIndex]
        .setCoefficients(IIRCoeff.makeHighPass(samplerate, crossoverPoint3, passQ));
        IIRFilHP[filterIndex]
        .processSamples(channelData,bufferSize);
        
    }
    // Band-pass 1
    else if (filterType == 2)
    {

        IIRFilHP[filterIndex+2]
        .setCoefficients(IIRCoeff.makeHighPass(samplerate, crossoverPoint1, passQ));
        IIRFilHP[filterIndex+2]
        .processSamples(channelData, bufferSize);

        IIRFilLP[filterIndex+2]
        .setCoefficients(IIRCoeff.makeLowPass(samplerate, crossoverPoint2, passQ));
        IIRFilLP[filterIndex+2]
        .processSamples(channelData, bufferSize);

    }
    // Band-pass 2
    else if (filterType == 3)
    {

        IIRFilHP[filterIndex+4]
        .setCoefficients(IIRCoeff.makeHighPass(samplerate, crossoverPoint2, passQ));
        IIRFilHP[filterIndex+4]
        .processSamples(channelData, bufferSize);

        IIRFilLP[filterIndex+4]
        .setCoefficients(IIRCoeff.makeLowPass(samplerate, crossoverPoint3, passQ));
        IIRFilLP[filterIndex+4]
        .processSamples(channelData, bufferSize);

    }
}


void CompressorAudioProcessor::compress(AudioSampleBuffer& buffer, int compressorIndex)
{
    // Code in this method was partially inspired by GitHub user djmoffat (https://github.com/djmoffat/JUCE-multibandCompressor)
    
    // A couple of precautionary if statements to ensure the threshold is not positive and the makeup gain is not negative
    if (threshold[compressorIndex] > 0)
    {
        threshold[compressorIndex] = 0;
    } else if (makeUpGain[compressorIndex] < 0)
    {
        makeUpGain[compressorIndex] = 0;
    }
    
    if ((threshold[compressorIndex] < 0 || makeUpGain[compressorIndex] != 0))
    {
        // Mono buffer creation in size of buffer
        monoBuffer.setSize(1, bufferSize);
        monoBuffer.clear();
        
        // Add buffer contents to both channels of monoBuffer
        monoBuffer.addFrom(0, 0, buffer, 0, 0, bufferSize, 0.5);
        monoBuffer.addFrom(0, 0, buffer, 1, 0, bufferSize, 0.5);
        
        // Calculate compressor radio through compressor function
        compressor(monoBuffer, 0, compressorIndex);
        
        // Apply control voltage (calculated in compressor function) to the buffer
        for (int i = 0; i < bufferSize; ++i)
        {
            buffer.getWritePointer(0)[i] *= c[i];
            buffer.getWritePointer(1)[i] *= c[i];
        }
    }
}


void CompressorAudioProcessor::compressor(AudioSampleBuffer &buffer, int channel, int compressorIndex)

{
    // Code in this method was inspired by a combination of Reiss and McPherson's compressor code (Reiss & McPherson 2014), and GitHub user djmoffat's implementation of this code in a multiband scenario (https://github.com/djmoffat/JUCE-multibandCompressor)
    
    // The attack and release parameters are defined at the beginning of every block as the time is takes for the system to reach 1-1/e of its initial value
    alphaAttack[compressorIndex] = exp(-1/(0.001 * samplerate * tauAttack[compressorIndex]));
    alphaRelease[compressorIndex]= exp(-1/(0.001 * samplerate * tauRelease[compressorIndex]));
    for (int j = 0 ; j < bufferSize ; ++j)
    {
        //Level detection - estimate level using peak detector
        if (fabs(buffer.getWritePointer(channel)[j]) < 0.000001)
        {
            // If the absolute value of x is below 0.000001, set the x gain value to -120dB
            x_g[j] =-120;
        }
        else
        {
            x_g[j] = 20*log10(fabs(buffer.getWritePointer(channel)[j]));    // Conversion to decibels
        }
        
            //Gain computer- static apply input/output curve
        if ((2* fabs(x_g[j]-threshold[compressorIndex])) <= kneeWidth[compressorIndex])
        {
            // Output gain calculation if input gain - threshold is equal to or below knee width
            y_g[j] = x_g[j] + (1/ratio[compressorIndex] -1) * pow(x_g[j]-threshold[compressorIndex]+kneeWidth[compressorIndex]/2,2) / (2*kneeWidth[compressorIndex]);
        }
        else if ((2*(x_g[j]-threshold[compressorIndex])) > kneeWidth[compressorIndex])
        {
            // Output gain calculation if input gain - threshold is equal to or above knee width
            y_g[j] = threshold[compressorIndex]+ (x_g[j] - threshold[compressorIndex]) / ratio[compressorIndex];
        }
            
        else
            // Output gain and input gain are equal otherwise
            y_g[j] = x_g[j];
            x_l[j] = x_g[j] - y_g[j];
            
        //Smoothing of gain through ballistics calculations
        if (x_l[0]>yL_prev[compressorIndex])
        {
            // If the level the input at index 0 is larger than level of the output in the prrevious buffer then apply smoothing with regard to attack
            y_l[j]=alphaAttack[compressorIndex] * yL_prev[compressorIndex] + (1 - alphaAttack[compressorIndex]) * x_l[j];
        }
        else
        {
            // Also apply smoothing to with regard to release
            y_l[j]=alphaRelease[compressorIndex] * yL_prev[compressorIndex] + (1 - alphaRelease[compressorIndex]) * x_l[j];
        }
        //find control voltage at index j, this voltage is applied to the buffer in ::compress
        c[j] = pow(10,(makeUpGain[compressorIndex] - y_l[j])/20);
        yL_prev[compressorIndex]=y_l[j];
    }
}

template <class T> const T& CompressorAudioProcessor::max( const T& a, const T& b )
{
  return (a < b) ? b : a;
}

void CompressorAudioProcessor::resetAll()
{
    for (int r = 0; r < numberOfCompressors; r++) {
        tauAttack[r] = 0;
        tauRelease[r] = 0.1;
        alphaAttack[r] = 0;
        alphaRelease[r] = 0;
        threshold[r] = 0;
        ratio[r] = 1;
        makeUpGain[r] = 0;
        yL_prev[r] = 0;
        kneeWidth[r] = 0.1;
    }

    for (int i = 0 ; i < bufferSize ; ++i)
    {
        x_g[i] = 0;    y_g[i] = 0;
        x_l[i] = 0;    y_l[i] = 0;
        c[i] = 0;
    }
}


float CompressorAudioProcessor::getThreshold()
{
    return *threshold;  //Pointer to an array, as this variable is used by 4 individual compressors
}
float CompressorAudioProcessor::getRatio()
{
    return *ratio;
}
float CompressorAudioProcessor::getGain()
{
    return *makeUpGain;
}
float CompressorAudioProcessor::getAttackTime()
{
    return *tauAttack;
}
float CompressorAudioProcessor::getReleaseTime()
{
    return *tauRelease;
}
float CompressorAudioProcessor::getKneeWidth()
{
    return *kneeWidth;
}
float CompressorAudioProcessor::getCrossoverPoint1()
{
    return crossoverPoint1;
}
float CompressorAudioProcessor::getCrossoverPoint2()
{
    return crossoverPoint2;
}
float CompressorAudioProcessor::getCrossoverPoint3()
{
    return crossoverPoint3;
}
float CompressorAudioProcessor::getPassQ()
{
    return passQ;
}
//-----------------------------------------------------
// The setter methods below set the GUI object value that called them in PluginEditor.cpp to the variable of corresponding index (to its relevant compressor)
void CompressorAudioProcessor::setThreshold(float T, int compressorIndex)
{
    threshold[compressorIndex] = T;
}
void CompressorAudioProcessor::setGain(float G, int compressorIndex)
{
    makeUpGain[compressorIndex] = G;
}
void CompressorAudioProcessor::setRatio(float R, int compressorIndex)
{
    ratio[compressorIndex] = R;
}
void CompressorAudioProcessor::setAttackTime(float A, int compressorIndex)
{
    tauAttack[compressorIndex] = A;
}
void CompressorAudioProcessor::setReleaseTime(float RT, int compressorIndex)
{
    tauRelease[compressorIndex] = RT;
}
void CompressorAudioProcessor::setKneeWidth(float K, int compressorIndex)
{
    kneeWidth[compressorIndex] = K;
}

void CompressorAudioProcessor::setCrossoverPoint1(float Lo)
{
    crossoverPoint1 = Lo;
}
void CompressorAudioProcessor::setCrossoverPoint2(float Mid)
{
    crossoverPoint2 = Mid;
}
void CompressorAudioProcessor::setCrossoverPoint3(float Hi)
{
    crossoverPoint3 = Hi;
}
void CompressorAudioProcessor::setPassQ(double Q)
{
    passQ = Q;
}

bool CompressorAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}
AudioProcessorEditor* CompressorAudioProcessor::createEditor()
{
    return new CompressorAudioProcessorEditor (*this);
}
//==============================================================================
void CompressorAudioProcessor::getStateInformation (MemoryBlock& destData)
{
//Use this to store your parameters in memory block, either as raw data, or use XML or ValueTree classes as intermediaries to make it easy to save and load complex data.
}
void CompressorAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
// Use this to restore your parameters from this memory block, whose contents will have been created by the getStateInformation() call.
}

// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new CompressorAudioProcessor();
}
int CompressorAudioProcessor::round(float inn)
{
    if (inn > 0) return (int) (inn + 0.5);
    else return (int) (inn - 0.5);
}
const String CompressorAudioProcessor::getName() const
{
    return JucePlugin_Name;
}
int CompressorAudioProcessor::getNumParameters()
{
    return 0;
}
float CompressorAudioProcessor::getParameter (int index)
{
    return 0.0f;
}
void CompressorAudioProcessor::setParameter (int index, float newValue)
{
}
const String CompressorAudioProcessor::getParameterName (int index)
{
    return std::string();
}
const String CompressorAudioProcessor::getParameterText (int index)
{
    return std::string();
}
const String CompressorAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}
const String CompressorAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}
bool CompressorAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}
bool CompressorAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}
bool CompressorAudioProcessor::silenceInProducesSilenceOut() const
{
#if JucePlugin_SilenceInProducesSilenceOut
    return true;
#else
    return false;
#endif
}
bool CompressorAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}
double CompressorAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}
bool CompressorAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}
bool CompressorAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}
int CompressorAudioProcessor::getNumPrograms()
{
    return 0;
}
int CompressorAudioProcessor::getCurrentProgram()
{
    return 0;
}
void CompressorAudioProcessor::setCurrentProgram (int index)
{
}
const String CompressorAudioProcessor::getProgramName (int index)
{
    return std::string();
}
void CompressorAudioProcessor::changeProgramName (int index, const String& newName)
{
}
