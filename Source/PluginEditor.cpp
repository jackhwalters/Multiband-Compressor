/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
CompressorAudioProcessorEditor::CompressorAudioProcessorEditor (CompressorAudioProcessor& p)
    : AudioProcessorEditor (&p),
    
    // First initialise all GUI parameters to 0 through inline implementation in the CompressorAudioProcessor constructor class
    processor (p),
    buttonONOFF (0),
    label (0),
    nameLabel(0),

    C1SliderThreshold (0),
    C1ThresholdLabel (0),
    C1SliderRatio (0),
    C1RatioLabel (0),
    C1SliderGain (0),
    C1GainLabel (0),
    C1SliderAttack (0),
    C1AttackLabel (0),
    C1SliderRelease (0),
    C1ReleaseLabel (0),
    C1KneeWidth (0),
    C1KneeWidthLabel (0),

    C2SliderThreshold (0),
    C2ThresholdLabel (0),
    C2SliderRatio (0),
    C2RatioLabel (0),
    C2SliderGain (0),
    C2GainLabel (0),
    C2SliderAttack (0),
    C2AttackLabel (0),
    C2SliderRelease (0),
    C2ReleaseLabel (0),
    C2KneeWidth (0),
    C2KneeWidthLabel (0),

    C3SliderThreshold (0),
    C3ThresholdLabel (0),
    C3SliderRatio (0),
    C3RatioLabel (0),
    C3SliderGain (0),
    C3GainLabel (0),
    C3SliderAttack (0),
    C3AttackLabel (0),
    C3SliderRelease (0),
    C3ReleaseLabel (0),
    C3KneeWidth (0),
    C3KneeWidthLabel (0),

    C4SliderThreshold (0),
    C4ThresholdLabel (0),
    C4SliderRatio (0),
    C4RatioLabel (0),
    C4SliderGain (0),
    C4GainLabel (0),
    C4SliderAttack (0),
    C4AttackLabel (0),
    C4SliderRelease (0),
    C4ReleaseLabel (0),
    C4KneeWidth (0),
    C4KneeWidthLabel (0),

    crossoverPoint1(0),
    crossoverPoint1Label(0),
    crossoverPoint2(0),
    crossoverPoint2Label(0),
    crossoverPoint3(0),
    crossoverPoint3Label(0),
    passQ(0),
    passQLabel(0)

// In the constructor parameters, every object in the GUI is assigned a class type, colour, range etc. Every object that will be interacted with by the user (i.e. is not a label) is also set as a listener
{
    cachedImage_Mattblack = ImageCache::getFromMemory (BinaryData::Mattblack_jpg, BinaryData::Mattblack_jpgSize);
    
    addAndMakeVisible (buttonONOFF = new TextButton (L"on off button"));
    buttonONOFF->setButtonText (L"ON / OFF");
    buttonONOFF->addListener (this);
    buttonONOFF->setColour (TextButton::buttonColourId, Colour (0xff615a5a));
    buttonONOFF->setColour (TextButton::buttonOnColourId, Colours::chartreuse);

    addAndMakeVisible (label = new Label (std::string(),
                                          L"Multiband Compressor"));
    label->setFont (Font (22.0000f, Font::bold));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));
    
    addAndMakeVisible (nameLabel = new Label (std::string(),
                                          L"Jack Walters"));
    nameLabel->setFont (Font (15.0000f, Font::bold));
    nameLabel->setJustificationType (Justification::centred);
    nameLabel->setEditable (false, false, false);
    nameLabel->setColour (TextEditor::textColourId, Colours::black);
    nameLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));
    
    addAndMakeVisible (crossoverPoint1Label = new Label (std::string(),
                                          L"Crossover point 1"));
    crossoverPoint1Label->setFont (Font (15.0000f, Font::bold));
    crossoverPoint1Label->setJustificationType (Justification::centred);
    crossoverPoint1Label->setEditable (false, false, false);
    crossoverPoint1Label->setColour (TextEditor::textColourId, Colours::black);
    crossoverPoint1Label->setColour (TextEditor::backgroundColourId, Colour (0x0));
    
    addAndMakeVisible (crossoverPoint2Label = new Label (std::string(),
                                          L"Crossover point 2"));
    crossoverPoint2Label->setFont (Font (15.0000f, Font::bold));
    crossoverPoint2Label->setJustificationType (Justification::centred);
    crossoverPoint2Label->setEditable (false, false, false);
    crossoverPoint2Label->setColour (TextEditor::textColourId, Colours::black);
    crossoverPoint2Label->setColour (TextEditor::backgroundColourId, Colour (0x0));
    
    addAndMakeVisible (crossoverPoint3Label = new Label (std::string(),
                                          L"Crossover point 3"));
    crossoverPoint3Label->setFont (Font (15.0000f, Font::bold));
    crossoverPoint3Label->setJustificationType (Justification::centred);
    crossoverPoint3Label->setEditable (false, false, false);
    crossoverPoint3Label->setColour (TextEditor::textColourId, Colours::black);
    crossoverPoint3Label->setColour (TextEditor::backgroundColourId, Colour (0x0));
    
    // C1

    addAndMakeVisible (C1SliderThreshold = new Slider (L"new slider"));
    C1SliderThreshold->setRange (-60, 0, -60);
    C1SliderThreshold->setSliderStyle (Slider::RotaryVerticalDrag);
    C1SliderThreshold->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C1SliderThreshold->addListener (this);

    addAndMakeVisible (C1ThresholdLabel = new Label (L"new label",
                                           L"Threshold"));
    C1ThresholdLabel->setFont (Font (15.0000f, Font::plain));
    C1ThresholdLabel->setJustificationType (Justification::centredLeft);
    C1ThresholdLabel->setEditable (false, false, false);
    C1ThresholdLabel->setColour (TextEditor::textColourId, Colours::black);
    C1ThresholdLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (C1SliderRatio = new Slider (L"new slider"));
    C1SliderRatio->setRange (1, 100, 0.1);
    C1SliderRatio->setSliderStyle (Slider::RotaryVerticalDrag);
    C1SliderRatio->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C1SliderRatio->addListener (this);

    addAndMakeVisible (C1RatioLabel = new Label (L"new label",
                                           L"Ratio"));
    C1RatioLabel->setFont (Font (15.0000f, Font::plain));
    C1RatioLabel->setJustificationType (Justification::centredLeft);
    C1RatioLabel->setEditable (false, false, false);
    C1RatioLabel->setColour (TextEditor::textColourId, Colours::black);
    C1RatioLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (C1SliderGain = new Slider (L"new slider"));
    C1SliderGain->setRange (-5, 5, 0.1);
    C1SliderGain->setSliderStyle (Slider::RotaryVerticalDrag);
    C1SliderGain->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C1SliderGain->addListener (this);

    addAndMakeVisible (C1GainLabel = new Label (L"new label",
                                           L"Gain"));
    C1GainLabel->setFont (Font (15.0000f, Font::plain));
    C1GainLabel->setJustificationType (Justification::centredLeft);
    C1GainLabel->setEditable (false, false, false);
    C1GainLabel->setColour (TextEditor::textColourId, Colours::black);
    C1GainLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (C1SliderAttack = new Slider (L"new slider"));
    C1SliderAttack->setRange (0.1, 80, 0.1);
    C1SliderAttack->setSliderStyle (Slider::RotaryVerticalDrag);
    C1SliderAttack->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C1SliderAttack->addListener (this);

    addAndMakeVisible (C1AttackLabel = new Label (L"new label",
                                           L"Attack Time (ms)"));
    C1AttackLabel->setFont (Font (15.0000f, Font::plain));
    C1AttackLabel->setJustificationType (Justification::centredLeft);
    C1AttackLabel->setEditable (false, false, false);
    C1AttackLabel->setColour (TextEditor::textColourId, Colours::black);
    C1AttackLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (C1SliderRelease = new Slider (L"new slider"));
    C1SliderRelease->setRange (0.1, 1000, 0.1);
    C1SliderRelease->setSliderStyle (Slider::RotaryVerticalDrag);
    C1SliderRelease->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C1SliderRelease->addListener (this);

    addAndMakeVisible (C1ReleaseLabel = new Label (L"new label",
                                           L"Release Time (ms)"));
    C1ReleaseLabel->setFont (Font (15.0000f, Font::plain));
    C1ReleaseLabel->setJustificationType (Justification::centredLeft);
    C1ReleaseLabel->setEditable (false, false, false);
    C1ReleaseLabel->setColour (TextEditor::textColourId, Colours::black);
    C1ReleaseLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));
    
    addAndMakeVisible (C1KneeWidth = new Slider (L"new slider"));
    C1KneeWidth->setRange (0, 20, 0.1);
    C1KneeWidth->setSliderStyle (Slider::RotaryVerticalDrag);
    C1KneeWidth->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C1KneeWidth->addListener (this);

    addAndMakeVisible (C1KneeWidthLabel = new Label (L"new label",
                                           L"Knee Width"));
    C1KneeWidthLabel->setFont (Font (15.0000f, Font::plain));
    C1KneeWidthLabel->setJustificationType (Justification::centredLeft);
    C1KneeWidthLabel->setEditable (false, false, false);
    C1KneeWidthLabel->setColour (TextEditor::textColourId, Colours::black);
    C1KneeWidthLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));
    
    // C2
    
    addAndMakeVisible (C2SliderThreshold = new Slider (L"new slider"));
    C2SliderThreshold->setRange (-60, 0, 0.1);
    C2SliderThreshold->setSliderStyle (Slider::RotaryVerticalDrag);
    C2SliderThreshold->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C2SliderThreshold->addListener (this);

    addAndMakeVisible (C2ThresholdLabel = new Label (L"new label",
                                           L"Threshold"));
    C2ThresholdLabel->setFont (Font (15.0000f, Font::plain));
    C2ThresholdLabel->setJustificationType (Justification::centredLeft);
    C2ThresholdLabel->setEditable (false, false, false);
    C2ThresholdLabel->setColour (TextEditor::textColourId, Colours::black);
    C2ThresholdLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (C2SliderRatio = new Slider (L"new slider"));
    C2SliderRatio->setRange (1, 100, 0.1);
    C2SliderRatio->setSliderStyle (Slider::RotaryVerticalDrag);
    C2SliderRatio->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C2SliderRatio->addListener (this);

    addAndMakeVisible (C2RatioLabel = new Label (L"new label",
                                           L"Ratio"));
    C2RatioLabel->setFont (Font (15.0000f, Font::plain));
    C2RatioLabel->setJustificationType (Justification::centredLeft);
    C2RatioLabel->setEditable (false, false, false);
    C2RatioLabel->setColour (TextEditor::textColourId, Colours::black);
    C2RatioLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (C2SliderGain = new Slider (L"new slider"));
    C2SliderGain->setRange (-5, 5, 0.1);
    C2SliderGain->setSliderStyle (Slider::RotaryVerticalDrag);
    C2SliderGain->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C2SliderGain->addListener (this);

    addAndMakeVisible (C2GainLabel = new Label (L"new label",
                                           L"Gain"));
    C2GainLabel->setFont (Font (15.0000f, Font::plain));
    C2GainLabel->setJustificationType (Justification::centredLeft);
    C2GainLabel->setEditable (false, false, false);
    C2GainLabel->setColour (TextEditor::textColourId, Colours::black);
    C2GainLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (C2SliderAttack = new Slider (L"new slider"));
    C2SliderAttack->setRange (0.1, 80, 0.1);
    C2SliderAttack->setSliderStyle (Slider::RotaryVerticalDrag);
    C2SliderAttack->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C2SliderAttack->addListener (this);

    addAndMakeVisible (C2AttackLabel = new Label (L"new label",
                                           L"Attack Time (ms)"));
    C2AttackLabel->setFont (Font (15.0000f, Font::plain));
    C2AttackLabel->setJustificationType (Justification::centredLeft);
    C2AttackLabel->setEditable (false, false, false);
    C2AttackLabel->setColour (TextEditor::textColourId, Colours::black);
    C2AttackLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (C2SliderRelease = new Slider (L"new slider"));
    C2SliderRelease->setRange (0.1, 1000, 0.1);
    C2SliderRelease->setSliderStyle (Slider::RotaryVerticalDrag);
    C2SliderRelease->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C2SliderRelease->addListener (this);

    addAndMakeVisible (C2ReleaseLabel = new Label (L"new label",
                                           L"Release Time (ms)"));
    C2ReleaseLabel->setFont (Font (15.0000f, Font::plain));
    C2ReleaseLabel->setJustificationType (Justification::centredLeft);
    C2ReleaseLabel->setEditable (false, false, false);
    C2ReleaseLabel->setColour (TextEditor::textColourId, Colours::black);
    C2ReleaseLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));
    
    addAndMakeVisible (C2KneeWidth = new Slider (L"new slider"));
    C2KneeWidth->setRange (0, 20, 0.1);
    C2KneeWidth->setSliderStyle (Slider::RotaryVerticalDrag);
    C2KneeWidth->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C2KneeWidth->addListener (this);

    addAndMakeVisible (C2KneeWidthLabel = new Label (L"new label",
                                           L"Knee Width"));
    C2KneeWidthLabel->setFont (Font (15.0000f, Font::plain));
    C2KneeWidthLabel->setJustificationType (Justification::centredLeft);
    C2KneeWidthLabel->setEditable (false, false, false);
    C2KneeWidthLabel->setColour (TextEditor::textColourId, Colours::black);
    C2KneeWidthLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));
    
    // C3
    
    addAndMakeVisible (C3SliderThreshold = new Slider (L"new slider"));
    C3SliderThreshold->setRange (-60, 0, 0.1);
    C3SliderThreshold->setSliderStyle (Slider::RotaryVerticalDrag);
    C3SliderThreshold->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C3SliderThreshold->addListener (this);

    addAndMakeVisible (C3ThresholdLabel = new Label (L"new label",
                                           L"Threshold"));
    C3ThresholdLabel->setFont (Font (15.0000f, Font::plain));
    C3ThresholdLabel->setJustificationType (Justification::centredLeft);
    C3ThresholdLabel->setEditable (false, false, false);
    C3ThresholdLabel->setColour (TextEditor::textColourId, Colours::black);
    C3ThresholdLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (C3SliderRatio = new Slider (L"new slider"));
    C3SliderRatio->setRange (1, 100, 0.1);
    C3SliderRatio->setSliderStyle (Slider::RotaryVerticalDrag);
    C3SliderRatio->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C3SliderRatio->addListener (this);

    addAndMakeVisible (C3RatioLabel = new Label (L"new label",
                                           L"Ratio"));
    C3RatioLabel->setFont (Font (15.0000f, Font::plain));
    C3RatioLabel->setJustificationType (Justification::centredLeft);
    C3RatioLabel->setEditable (false, false, false);
    C3RatioLabel->setColour (TextEditor::textColourId, Colours::black);
    C3RatioLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (C3SliderGain = new Slider (L"new slider"));
    C3SliderGain->setRange (-5, 5, 0.1);
    C3SliderGain->setSliderStyle (Slider::RotaryVerticalDrag);
    C3SliderGain->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C3SliderGain->addListener (this);

    addAndMakeVisible (C3GainLabel = new Label (L"new label",
                                           L"Gain"));
    C3GainLabel->setFont (Font (15.0000f, Font::plain));
    C3GainLabel->setJustificationType (Justification::centredLeft);
    C3GainLabel->setEditable (false, false, false);
    C3GainLabel->setColour (TextEditor::textColourId, Colours::black);
    C3GainLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (C3SliderAttack = new Slider (L"new slider"));
    C3SliderAttack->setRange (0.1, 80, 0.1);
    C3SliderAttack->setSliderStyle (Slider::RotaryVerticalDrag);
    C3SliderAttack->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C3SliderAttack->addListener (this);

    addAndMakeVisible (C3AttackLabel = new Label (L"new label",
                                           L"Attack Time (ms)"));
    C3AttackLabel->setFont (Font (15.0000f, Font::plain));
    C3AttackLabel->setJustificationType (Justification::centredLeft);
    C3AttackLabel->setEditable (false, false, false);
    C3AttackLabel->setColour (TextEditor::textColourId, Colours::black);
    C3AttackLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (C3SliderRelease = new Slider (L"new slider"));
    C3SliderRelease->setRange (0.1, 1000, 0.1);
    C3SliderRelease->setSliderStyle (Slider::RotaryVerticalDrag);
    C3SliderRelease->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C3SliderRelease->addListener (this);

    addAndMakeVisible (C3ReleaseLabel = new Label (L"new label",
                                           L"Release Time (ms)"));
    C3ReleaseLabel->setFont (Font (15.0000f, Font::plain));
    C3ReleaseLabel->setJustificationType (Justification::centredLeft);
    C3ReleaseLabel->setEditable (false, false, false);
    C3ReleaseLabel->setColour (TextEditor::textColourId, Colours::black);
    C3ReleaseLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));
    
    addAndMakeVisible (C3KneeWidth = new Slider (L"new slider"));
    C3KneeWidth->setRange (0, 20, 0.1);
    C3KneeWidth->setSliderStyle (Slider::RotaryVerticalDrag);
    C3KneeWidth->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C3KneeWidth->addListener (this);

    addAndMakeVisible (C3KneeWidthLabel = new Label (L"new label",
                                           L"Knee Width"));
    C3KneeWidthLabel->setFont (Font (15.0000f, Font::plain));
    C3KneeWidthLabel->setJustificationType (Justification::centredLeft);
    C3KneeWidthLabel->setEditable (false, false, false);
    C3KneeWidthLabel->setColour (TextEditor::textColourId, Colours::black);
    C3KneeWidthLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));
    
    // C4
    
    addAndMakeVisible (C4SliderThreshold = new Slider (L"new slider"));
    C4SliderThreshold->setRange (-60, 0, 0.1);
    C4SliderThreshold->setSliderStyle (Slider::RotaryVerticalDrag);
    C4SliderThreshold->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C4SliderThreshold->addListener (this);

    addAndMakeVisible (C4ThresholdLabel = new Label (L"new label",
                                           L"Threshold"));
    C4ThresholdLabel->setFont (Font (15.0000f, Font::plain));
    C4ThresholdLabel->setJustificationType (Justification::centredLeft);
    C4ThresholdLabel->setEditable (false, false, false);
    C4ThresholdLabel->setColour (TextEditor::textColourId, Colours::black);
    C4ThresholdLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (C4SliderRatio = new Slider (L"new slider"));
    C4SliderRatio->setRange (1, 100, 0.1);
    C4SliderRatio->setSliderStyle (Slider::RotaryVerticalDrag);
    C4SliderRatio->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C4SliderRatio->addListener (this);

    addAndMakeVisible (C4RatioLabel = new Label (L"new label",
                                           L"Ratio"));
    C4RatioLabel->setFont (Font (15.0000f, Font::plain));
    C4RatioLabel->setJustificationType (Justification::centredLeft);
    C4RatioLabel->setEditable (false, false, false);
    C4RatioLabel->setColour (TextEditor::textColourId, Colours::black);
    C4RatioLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (C4SliderGain = new Slider (L"new slider"));
    C4SliderGain->setRange (-5, 5, 0.1);
    C4SliderGain->setSliderStyle (Slider::RotaryVerticalDrag);
    C4SliderGain->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C4SliderGain->addListener (this);

    addAndMakeVisible (C4GainLabel = new Label (L"new label",
                                           L"Gain"));
    C4GainLabel->setFont (Font (15.0000f, Font::plain));
    C4GainLabel->setJustificationType (Justification::centredLeft);
    C4GainLabel->setEditable (false, false, false);
    C4GainLabel->setColour (TextEditor::textColourId, Colours::black);
    C4GainLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (C4SliderAttack = new Slider (L"new slider"));
    C4SliderAttack->setRange (0.1, 80, 0.1);
    C4SliderAttack->setSliderStyle (Slider::RotaryVerticalDrag);
    C4SliderAttack->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C4SliderAttack->addListener (this);

    addAndMakeVisible (C4AttackLabel = new Label (L"new label",
                                           L"Attack Time (ms)"));
    C4AttackLabel->setFont (Font (15.0000f, Font::plain));
    C4AttackLabel->setJustificationType (Justification::centredLeft);
    C4AttackLabel->setEditable (false, false, false);
    C4AttackLabel->setColour (TextEditor::textColourId, Colours::black);
    C4AttackLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (C4SliderRelease = new Slider (L"new slider"));
    C4SliderRelease->setRange (0.1, 1000, 0.1);
    C4SliderRelease->setSliderStyle (Slider::RotaryVerticalDrag);
    C4SliderRelease->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C4SliderRelease->addListener (this);

    addAndMakeVisible (C4ReleaseLabel = new Label (L"new label",
                                           L"Release Time (ms)"));
    C4ReleaseLabel->setFont (Font (15.0000f, Font::plain));
    C4ReleaseLabel->setJustificationType (Justification::centredLeft);
    C4ReleaseLabel->setEditable (false, false, false);
    C4ReleaseLabel->setColour (TextEditor::textColourId, Colours::black);
    C4ReleaseLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));
    
    addAndMakeVisible (C4KneeWidth = new Slider (L"new slider"));
    C4KneeWidth->setRange (0, 20, 0.1);
    C4KneeWidth->setSliderStyle (Slider::RotaryVerticalDrag);
    C4KneeWidth->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    C4KneeWidth->addListener (this);

    addAndMakeVisible (C4KneeWidthLabel = new Label (L"new label",
                                           L"Knee Width"));
    C4KneeWidthLabel->setFont (Font (15.0000f, Font::plain));
    C4KneeWidthLabel->setJustificationType (Justification::centredLeft);
    C4KneeWidthLabel->setEditable (false, false, false);
    C4KneeWidthLabel->setColour (TextEditor::textColourId, Colours::black);
    C4KneeWidthLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));
    
    // Band crossoverpoints
    
    addAndMakeVisible (crossoverPoint1 = new Slider (L"new slider"));
    crossoverPoint1->setRange (1, 16000, 1);
    crossoverPoint1->setValue((500));
    crossoverPoint1->setSliderStyle (Slider::LinearHorizontal);
    crossoverPoint1->setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    crossoverPoint1->setPopupDisplayEnabled (true, true, this, 2000);
    crossoverPoint1->addListener (this);
    
    addAndMakeVisible (crossoverPoint2 = new Slider (L"new slider"));
    crossoverPoint2->setRange (1, 16000, 1);
    crossoverPoint2->setValue((2000));
    crossoverPoint2->setSliderStyle (Slider::LinearHorizontal);
    crossoverPoint2->setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    crossoverPoint2->setPopupDisplayEnabled (true, true, this, 2000);
    crossoverPoint2->addListener (this);
    
    addAndMakeVisible (crossoverPoint3 = new Slider (L"new slider"));
    crossoverPoint3->setRange (1, 16000, 1);
    crossoverPoint3->setValue((4000));
    crossoverPoint3->setSliderStyle (Slider::LinearHorizontal);
    crossoverPoint3->setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    crossoverPoint3->setPopupDisplayEnabled (true, true, this, 2000);
    crossoverPoint3->addListener (this);
    
    addAndMakeVisible (passQ = new Slider (L"new slider"));
    passQ->setRange (0, 20, 0.1);
    passQ->setValue(2.0);
    passQ->setSliderStyle (Slider::RotaryVerticalDrag);
    passQ->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    passQ->addListener (this);
    
    addAndMakeVisible (passQLabel = new Label (L"new label",
                                           L"Filter Q"));
    passQLabel->setFont (Font (15.0000f, Font::plain));
    passQLabel->setJustificationType (Justification::centredLeft);
    passQLabel->setEditable (false, false, false);
    passQLabel->setColour (TextEditor::textColourId, Colours::black);
    passQLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));
    
    addAndMakeVisible (resizer = new ResizableCornerComponent (this, &resizeLimits));
    resizeLimits.setSizeLimits (150, 150, 850, 290);
    setSize (800, 800);
    buttonONOFF->setClickingTogglesState(true);
    startTimer (50);
}


// Destructor will run when program is terminated, and in doing so will delete the pointer and set it to null
CompressorAudioProcessorEditor::~CompressorAudioProcessorEditor()
{
    deleteAndZero (buttonONOFF);
    deleteAndZero (label);
    deleteAndZero (nameLabel);
    deleteAndZero (crossoverPoint1Label);
    deleteAndZero (crossoverPoint2Label);
    deleteAndZero (crossoverPoint3Label);
    
    deleteAndZero (C1SliderThreshold);
    deleteAndZero (C1ThresholdLabel);
    deleteAndZero (C1SliderRatio);
    deleteAndZero (C1RatioLabel);
    deleteAndZero (C1SliderGain);
    deleteAndZero (C1GainLabel);
    deleteAndZero (C1SliderAttack);
    deleteAndZero (C1AttackLabel);
    deleteAndZero (C1SliderRelease);
    deleteAndZero (C1ReleaseLabel);
    deleteAndZero (C1KneeWidth);
    deleteAndZero (C1KneeWidthLabel);
    
    deleteAndZero (C2SliderThreshold);
    deleteAndZero (C2ThresholdLabel);
    deleteAndZero (C2SliderRatio);
    deleteAndZero (C2RatioLabel);
    deleteAndZero (C2SliderGain);
    deleteAndZero (C2GainLabel);
    deleteAndZero (C2SliderAttack);
    deleteAndZero (C2AttackLabel);
    deleteAndZero (C2SliderRelease);
    deleteAndZero (C2ReleaseLabel);
    deleteAndZero (C2KneeWidth);
    deleteAndZero (C2KneeWidthLabel);
    
    deleteAndZero (C3SliderThreshold);
    deleteAndZero (C3ThresholdLabel);
    deleteAndZero (C3SliderRatio);
    deleteAndZero (C3RatioLabel);
    deleteAndZero (C3SliderGain);
    deleteAndZero (C3GainLabel);
    deleteAndZero (C3SliderAttack);
    deleteAndZero (C3AttackLabel);
    deleteAndZero (C3SliderRelease);
    deleteAndZero (C3ReleaseLabel);
    deleteAndZero (C3KneeWidth);
    deleteAndZero (C3KneeWidthLabel);
    
    deleteAndZero (C4SliderThreshold);
    deleteAndZero (C4ThresholdLabel);
    deleteAndZero (C4SliderRatio);
    deleteAndZero (C4RatioLabel);
    deleteAndZero (C4SliderGain);
    deleteAndZero (C4GainLabel);
    deleteAndZero (C4SliderAttack);
    deleteAndZero (C4AttackLabel);
    deleteAndZero (C4SliderRelease);
    deleteAndZero (C4ReleaseLabel);
    deleteAndZero (C4KneeWidth);
    deleteAndZero (C4KneeWidthLabel);
    
    deleteAndZero (crossoverPoint1);
    deleteAndZero (crossoverPoint2);
    deleteAndZero (crossoverPoint3);
    deleteAndZero (passQ);
    deleteAndZero (passQLabel);
}

//==============================================================================
void CompressorAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colour (0xff3e3a3a));

    g.setColour (Colours::silver);
    g.fillRoundedRectangle (0.0f, (float) (-1), 800.0f, 60.0f,
        10.0000f);

    g.drawImage(cachedImage_Mattblack, 0, 60, 800, 740, 0, 0, 400,
        400, false);
}

// This method sets the bounds of every object in the GUI
void CompressorAudioProcessorEditor::resized()
{
    buttonONOFF->setBounds (10, 70, 125, 50);
    label->setBounds (15, 5, 120, 49);
    nameLabel->setBounds(680, 5, 120, 49);
    crossoverPoint1Label->setBounds (645, 620, 150, 40);
    crossoverPoint2Label->setBounds (645, 680, 150, 40);
    crossoverPoint3Label->setBounds (645, 740, 150, 40);
    
    C1SliderThreshold->setBounds (512, 120, 160, 80);
        C1ThresholdLabel->setBounds (555, 200, 91, 24);
    C1SliderRatio->setBounds (0, 120, 160, 80);
        C1RatioLabel->setBounds (60, 200, 50, 24);
    C1SliderGain->setBounds (640, 120, 160, 80);
        C1GainLabel->setBounds (700, 200, 52, 24);
    C1SliderAttack->setBounds (128, 120, 160, 80);
        C1AttackLabel->setBounds (150, 200, 120, 24);
    C1SliderRelease->setBounds (256, 120, 160, 80);
        C1ReleaseLabel->setBounds (275, 200, 120, 24);
    C1KneeWidth->setBounds (384, 120, 160, 80);
        C1KneeWidthLabel->setBounds (425, 200, 120, 24);
    
    C2SliderThreshold->setBounds (512, 240, 160, 80);
        C2ThresholdLabel->setBounds (555, 320, 91, 24);
    C2SliderRatio->setBounds (0, 240, 160, 80);
        C2RatioLabel->setBounds (60, 320, 50, 24);
    C2SliderGain->setBounds (640, 240, 160, 80);
        C2GainLabel->setBounds (700, 320, 52, 24);
    C2SliderAttack->setBounds (128, 240, 160, 80);
        C2AttackLabel->setBounds (150, 320, 120, 24);
    C2SliderRelease->setBounds (256, 240, 160, 80);
        C2ReleaseLabel->setBounds (275, 320, 120, 24);
    C2KneeWidth->setBounds (384, 240, 160, 80);
        C2KneeWidthLabel->setBounds (425, 320, 120, 24);
    
    C3SliderThreshold->setBounds (512, 360, 160, 80);
        C3ThresholdLabel->setBounds (555, 440, 91, 24);
    C3SliderRatio->setBounds (0, 360, 160, 80);
        C3RatioLabel->setBounds (60, 440, 50, 24);
    C3SliderGain->setBounds (640, 360, 160, 80);
        C3GainLabel->setBounds (700, 440, 52, 24);
    C3SliderAttack->setBounds (128, 360, 160, 80);
        C3AttackLabel->setBounds (150, 440, 120, 24);
    C3SliderRelease->setBounds (256, 360, 160, 80);
        C3ReleaseLabel->setBounds (275, 440, 120, 24);
    C3KneeWidth->setBounds (384, 360, 160, 80);
        C3KneeWidthLabel->setBounds (425, 440, 120, 24);
    
    C4SliderThreshold->setBounds (512, 480, 160, 80);
        C4ThresholdLabel->setBounds (555, 560, 91, 24);
    C4SliderRatio->setBounds (0, 480, 160, 80);
        C4RatioLabel->setBounds (60, 560, 50, 24);
    C4SliderGain->setBounds (640, 480, 160, 80);
        C4GainLabel->setBounds (700, 560, 52, 24);
    C4SliderAttack->setBounds (128, 480, 160, 80);
        C4AttackLabel->setBounds (150, 560, 120, 24);
    C4SliderRelease->setBounds (256, 480, 160, 80);
        C4ReleaseLabel->setBounds (275, 560, 120, 24);
    C4KneeWidth->setBounds (384, 480, 160, 80);
        C4KneeWidthLabel->setBounds (425, 560, 120, 24);
    
    crossoverPoint1->setBounds (140, 630, 500, 20);
    crossoverPoint2->setBounds (140, 690, 500, 20);
    crossoverPoint3->setBounds (140, 750, 500, 20);
    passQ->setBounds (-10, 650, 160, 80);
    passQLabel->setBounds (42, 735, 120, 24);
}

// ::buttonClicked and ::sliderValueChanged are methods parese information sources from the buttonClicked and sliderValueChanged methods in CompressorAudioProcessorEditor and subsequently send their values to corresponding methods in PluginProcessor, which will in turn send this value to relevant parameters in the audio processing functions
void CompressorAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == buttonONOFF)
    {
        //[UserButtonCode_buttonONOFF] -- add your button handler code here..
        getProcessor(0)->compressorONOFF = buttonONOFF->getToggleState();
        //[/UserButtonCode_buttonONOFF]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void CompressorAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    // C1
    
    if (sliderThatWasMoved == C1SliderThreshold)
    {
        //[UserSliderCode_C1SliderThreshold] -- add your slider handling code here..
        getProcessor(0)->setThreshold(C1SliderThreshold->getValue(),0);
        //[/UserSliderCode_C1SliderThreshold]
    }
    else if (sliderThatWasMoved == C1SliderRatio)
    {
        //[UserSliderCode_C1SliderRatio] -- add your slider handling code here..
        getProcessor(0)->setRatio(C1SliderRatio->getValue(),0);
        //[/UserSliderCode_C1SliderRatio]
    }
    else if (sliderThatWasMoved == C1SliderGain)
    {
        //[UserSliderCode_C1SliderGain] -- add your slider handling code here..
        getProcessor(0)->setGain(C1SliderGain->getValue(),0);
        //[/UserSliderCode_C1SliderGain]
    }
    else if (sliderThatWasMoved == C1SliderAttack)
    {
        //[UserSliderCode_C1SliderAttack] -- add your slider handling code here..
        getProcessor(0)->setAttackTime(C1SliderAttack->getValue(),0);
        //[/UserSliderCode_C1SliderAttack]
    }
    else if (sliderThatWasMoved == C1SliderRelease)
    {
        //[UserSliderCode_C1SliderRelease] -- add your slider handling code here..
        getProcessor(0)->setReleaseTime(C1SliderRelease->getValue(),0);
        //[/UserSliderCode_C1SliderRelease]
    } else if (sliderThatWasMoved == C1KneeWidth)
    {
        //[UserSliderCode_C1SliderRelease] -- add your slider handling code here..
        getProcessor(0)->setKneeWidth(C1KneeWidth->getValue(),0);
        //[/UserSliderCode_C1SliderRelease]
    }
    
    // C2
    
    if (sliderThatWasMoved == C2SliderThreshold)
    {
        //[UserSliderCode_C1SliderThreshold] -- add your slider handling code here..
        getProcessor(1)->setThreshold(C2SliderThreshold->getValue(),1);
        //[/UserSliderCode_C1SliderThreshold]
    }
    else if (sliderThatWasMoved == C2SliderRatio)
    {
        //[UserSliderCode_C1SliderRatio] -- add your slider handling code here..
        getProcessor(1)->setRatio(C2SliderRatio->getValue(),1);
        //[/UserSliderCode_C1SliderRatio]
    }
    else if (sliderThatWasMoved == C2SliderGain)
    {
        //[UserSliderCode_C1SliderGain] -- add your slider handling code here..
        getProcessor(1)->setGain(C2SliderGain->getValue(),1);
        //[/UserSliderCode_C1SliderGain]
    }
    else if (sliderThatWasMoved == C2SliderAttack)
    {
        //[UserSliderCode_C1SliderAttack] -- add your slider handling code here..
        getProcessor(1)->setAttackTime(C2SliderAttack->getValue(),1);
        //[/UserSliderCode_C1SliderAttack]
    }
    else if (sliderThatWasMoved == C2SliderRelease)
    {
        //[UserSliderCode_C1SliderRelease] -- add your slider handling code here..
        getProcessor(1)->setReleaseTime(C2SliderRelease->getValue(),1);
        //[/UserSliderCode_C1SliderRelease]
    } else if (sliderThatWasMoved == C2KneeWidth)
    {
        //[UserSliderCode_C1SliderRelease] -- add your slider handling code here..
        getProcessor(1)->setKneeWidth(C2KneeWidth->getValue(),1);
        //[/UserSliderCode_C1SliderRelease]
    }
    
    // C3
    
    if (sliderThatWasMoved == C3SliderThreshold)
    {
        //[UserSliderCode_C1SliderThreshold] -- add your slider handling code here..
        getProcessor(2)->setThreshold(C3SliderThreshold->getValue(),2);
        //[/UserSliderCode_C1SliderThreshold]
    }
    else if (sliderThatWasMoved == C3SliderRatio)
    {
        //[UserSliderCode_C1SliderRatio] -- add your slider handling code here..
        getProcessor(2)->setRatio(C3SliderRatio->getValue(),2);
        //[/UserSliderCode_C1SliderRatio]
    }
    else if (sliderThatWasMoved == C3SliderGain)
    {
        //[UserSliderCode_C1SliderGain] -- add your slider handling code here..
        getProcessor(2)->setGain(C3SliderGain->getValue(),2);
        //[/UserSliderCode_C1SliderGain]
    }
    else if (sliderThatWasMoved == C3SliderAttack)
    {
        //[UserSliderCode_C1SliderAttack] -- add your slider handling code here..
        getProcessor(2)->setAttackTime(C3SliderAttack->getValue(),2);
        //[/UserSliderCode_C1SliderAttack]
    }
    else if (sliderThatWasMoved == C3SliderRelease)
    {
        //[UserSliderCode_C1SliderRelease] -- add your slider handling code here..
        getProcessor(2)->setReleaseTime(C3SliderRelease->getValue(),2);
        //[/UserSliderCode_C1SliderRelease]
    } else if (sliderThatWasMoved == C3KneeWidth)
    {
        //[UserSliderCode_C1SliderRelease] -- add your slider handling code here..
        getProcessor(2)->setKneeWidth(C3KneeWidth->getValue(),2);
        //[/UserSliderCode_C1SliderRelease]
    }
    
    // C4
    
    if (sliderThatWasMoved == C4SliderThreshold)
    {
        //[UserSliderCode_C1SliderThreshold] -- add your slider handling code here..
        getProcessor(3)->setThreshold(C4SliderThreshold->getValue(),3);
        //[/UserSliderCode_C1SliderThreshold]
    }
    else if (sliderThatWasMoved == C4SliderRatio)
    {
        //[UserSliderCode_C1SliderRatio] -- add your slider handling code here..
        getProcessor(3)->setRatio(C4SliderRatio->getValue(),3);
        //[/UserSliderCode_C1SliderRatio]
    }
    else if (sliderThatWasMoved == C4SliderGain)
    {
        //[UserSliderCode_C1SliderGain] -- add your slider handling code here..
        getProcessor(3)->setGain(C4SliderGain->getValue(),3);
        //[/UserSliderCode_C1SliderGain]
    }
    else if (sliderThatWasMoved == C4SliderAttack)
    {
        //[UserSliderCode_C1SliderAttack] -- add your slider handling code here..
        getProcessor(3)->setAttackTime(C4SliderAttack->getValue(),3);
        //[/UserSliderCode_C1SliderAttack]
    }
    else if (sliderThatWasMoved == C4SliderRelease)
    {
        //[UserSliderCode_C1SliderRelease] -- add your slider handling code here..
         getProcessor(3)->setReleaseTime(C4SliderRelease->getValue(),3);
        //[/UserSliderCode_C1SliderRelease]
    } else if (sliderThatWasMoved == C4KneeWidth)
    {
        //[UserSliderCode_C1SliderRelease] -- add your slider handling code here..
        getProcessor(3)->setKneeWidth(C3KneeWidth->getValue(),3);
        //[/UserSliderCode_C1SliderRelease]
    }
    
    // Band crossover
    
    else if (sliderThatWasMoved == crossoverPoint1)
    {
        getProcessor(0)->setCrossoverPoint1(crossoverPoint1->getValue());
    }
    else if (sliderThatWasMoved == crossoverPoint2)
    {
        getProcessor(1)->setCrossoverPoint2(crossoverPoint2->getValue());
    }
    else if (sliderThatWasMoved == crossoverPoint3)
    {
        getProcessor(2)->setCrossoverPoint3(crossoverPoint3->getValue());
    }
    else if (sliderThatWasMoved == passQ)
    {
        getProcessor(0)->setPassQ(passQ->getValue());
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

// This timer periodically checks whether any of the filter's parameters have changed
void CompressorAudioProcessorEditor::timerCallback()
{

        // Display the ON/OFF button in its correct state
    if (buttonONOFF->getToggleState())
    {
        buttonONOFF->setToggleState(true, dontSendNotification);
    }
    else
    {
        buttonONOFF->setToggleState(false, dontSendNotification);
    }
}
