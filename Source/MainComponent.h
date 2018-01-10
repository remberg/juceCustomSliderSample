/*
  ==============================================================================

    Created: 14 Dec 2017 10:16:04am
    Author:  Stefan Remberg

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "myLookAndFeel.h"
//==============================================================================

class MainContentComponent : public Component
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    myLookAndFeelV1 myLookAndFeelV1;
    myLookAndFeelV2 myLookAndFeelV2;
    myLookAndFeelV3 myLookAndFeelV3;
    Slider myKnobSlider1;
    Slider myKnobSlider2;
    Slider myKnobSlider3;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
