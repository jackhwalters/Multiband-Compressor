/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
// The CompressorAudioProcessorEditor class inherits from the AudioProcessorEditor, Timer, Slider::Listener and Button::Listener classes
class CompressorAudioProcessorEditor  : public AudioProcessorEditor, public Timer, public Slider::Listener, public Button::Listener

{
public:
    CompressorAudioProcessorEditor (CompressorAudioProcessor&);
    ~CompressorAudioProcessorEditor();

//==============================================================================
    
    // Public methods to the CompressorAudioProcessorEditor class that are called when the GUI is interacted with
    
    void timerCallback();
    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void sliderValueChanged (Slider* sliderThatWasMoved);
    
    // Binary resources used for GUI background image caching
    
    static const char* Mattblack;
    static const int MattblackSize;

private:
    CompressorAudioProcessor& processor;
    
    ScopedPointer<ResizableCornerComponent> resizer;
    ComponentBoundsConstrainer resizeLimits;


    AudioPlayHead::CurrentPositionInfo lastDisplayedPosition;

    CompressorAudioProcessor* getProcessor(int index) const
    {
        return static_cast <CompressorAudioProcessor*> (getAudioProcessor());
    }

    void displayPositionInfo (const AudioPlayHead::CurrentPositionInfo& pos);

    // Declaring pointers of various JUCE GUI class types

    TextButton* buttonONOFF;
    
    Label* label;
    Label* nameLabel;
    
    Slider* C1SliderThreshold;
    Label* C1ThresholdLabel;
    Slider* C1SliderRatio;
    Label* C1RatioLabel;
    Slider* C1SliderGain;
    Label* C1GainLabel;
    Slider* C1SliderAttack;
    Label* C1AttackLabel;
    Slider* C1SliderRelease;
    Label* C1ReleaseLabel;
    Slider* C1KneeWidth;
    Label* C1KneeWidthLabel;
    
    Slider* C2SliderThreshold;
    Label* C2ThresholdLabel;
    Slider* C2SliderRatio;
    Label* C2RatioLabel;
    Slider* C2SliderGain;
    Label* C2GainLabel;
    Slider* C2SliderAttack;
    Label* C2AttackLabel;
    Slider* C2SliderRelease;
    Label* C2ReleaseLabel;
    Slider* C2KneeWidth;
    Label* C2KneeWidthLabel;
    
    Slider* C3SliderThreshold;
    Label* C3ThresholdLabel;
    Slider* C3SliderRatio;
    Label* C3RatioLabel;
    Slider* C3SliderGain;
    Label* C3GainLabel;
    Slider* C3SliderAttack;
    Label* C3AttackLabel;
    Slider* C3SliderRelease;
    Label* C3ReleaseLabel;
    Slider* C3KneeWidth;
    Label* C3KneeWidthLabel;
    
    Slider* C4SliderThreshold;
    Label* C4ThresholdLabel;
    Slider* C4SliderRatio;
    Label* C4RatioLabel;
    Slider* C4SliderGain;
    Label* C4GainLabel;
    Slider* C4SliderAttack;
    Label* C4AttackLabel;
    Slider* C4SliderRelease;
    Label* C4ReleaseLabel;
    Slider* C4KneeWidth;
    Label* C4KneeWidthLabel;
    
    Slider* crossoverPoint1;
    Label* crossoverPoint1Label;
    Slider* crossoverPoint2;
    Label* crossoverPoint2Label;
    Slider* crossoverPoint3;
    Label* crossoverPoint3Label;
    Slider* passQ;
    Label* passQLabel;
    
    // Create a null image object that will be implemented in PluginProcessor.cpp
    
    Image cachedImage_Mattblack;

//==============================================================================
//     (prevent copy constructor and operator= being generated..)
//    CompressorAudioProcessorEditor (const CompressorAudioProcessorEditor&);
//    const CompressorAudioProcessorEditor& operator= (const CompressorAudioProcessorEditor&);

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CompressorAudioProcessorEditor)
};
