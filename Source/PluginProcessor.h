/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//#define NUMCOMPRESSORS 3

//==============================================================================
/**
*/
class CompressorAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    //Constructor and destructor
    CompressorAudioProcessor();
    ~CompressorAudioProcessor();

    int bufferSize;
    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

//   #ifndef JucePlugin_PreferredChannelConfigurations
//    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
//   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

//    void crossover (float* buffer, float Lo, float Mid, float Hi, float Q, float gainFactor, int filterType, int filterIndex);
    void crossover(float* channelData, int filterType, int filterIndex);
    void compressor (AudioSampleBuffer &buffer, int channel, int compressorIndex);
    void compress (AudioSampleBuffer& buffer, int compressorIndex);

    template <class T> const T& max ( const T& a, const T& b );
    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    AudioPlayHead::CurrentPositionInfo lastPosInfo;
    
       int round(float inn);
    //==============================================================================
    const String getName() const override;

    int getNumParameters() override;

    float getParameter (int index) override;
    void setParameter (int index, float newValue) override;

    const String getParameterName (int index) override;
    const String getParameterText (int index) override;

    const String getInputChannelName (int channelIndex) const override;
    const String getOutputChannelName (int channelIndex) const override;
    bool isInputChannelStereoPair (int index) const override;
    bool isOutputChannelStereoPair (int index) const override;

    bool silenceInProducesSilenceOut() const override;
    double getTailLengthSeconds() const override;
    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;

    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    // Compressors value methods

    float getThreshold();
    float getRatio();
    float getGain();
    float getAttackTime();
    float getReleaseTime();
    float getKneeWidth();
    void setThreshold(float T, int compressorIndex);
    void setGain(float G, int compressorIndex);
    void setRatio(float R, int compressorIndex);
    void setAttackTime(float A, int compressorIndex);
    void setReleaseTime(float R, int compressorIndex);
    void setKneeWidth(float K, int compressorIndex);
    
    // Filter and crossover methods
    
    float getCrossoverPoint1();
    float getCrossoverPoint2();
    float getCrossoverPoint3();
    float getPassQ();
    void setCrossoverPoint1(float Hi);
    void setCrossoverPoint2(float Mid);
    void setCrossoverPoint3(float Hi);
    void setPassQ(double Q);
    void resetAll();

    // parameters

    bool compressorONOFF;
    int M;    // Variable used to store number of input channels
    bool autoTime;
    float numberOfCompressors;


private:
    //These variables are used to enable parallel processing in the ::prepareToPlay ::processBlock, ::compress and ::compressor methods in PluginProcessor.cpp
    AudioSampleBuffer inputBuffer;
    AudioSampleBuffer processBuffer;
    AudioSampleBuffer monoBuffer;
    
//    int bufferSize;
//these are used to persist UI's size- values are stored along with filter's other parameters, and UI component will update them when it gets resized.

    int lastUIWidth, lastUIHeight;
            
    HeapBlock <float> x_g, x_l,y_g, y_l,c;// input, output, control
            // parameters
    
    float ratio[4];
    float threshold[4];
    float makeUpGain[4];
    float tauAttack[4];
    float tauRelease[4];
    float alphaAttack[4];
    float alphaRelease[4];
    float kneeWidth[4];
    float yL_prev[4];
    
    // Crossover points and Q factor declared as individual objects as different instances of the objects do not need to be accessed simultaneously
    float crossoverPoint1,crossoverPoint2,crossoverPoint3,passQ;
    
    int samplerate;
    
    
    // IIR filter objects are also declared in arrays to that individual filter objects cans be indexed in the ::crossover method in CompressorAudioProcessor
    IIRFilter IIRFilLP[5];
    IIRFilter IIRFilHP[5];
    
    IIRCoefficients IIRCoeff;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CompressorAudioProcessor)
};
