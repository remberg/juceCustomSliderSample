
/*
  ==============================================================================

    Created: 14 Dec 2017 10:16:04am
    Author:  Stefan Remberg

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainContentComponent::MainContentComponent()
{
	addAndMakeVisible(myKnobSlider1);
    	myKnobSlider1.setLookAndFeel(&myLookAndFeelV1);
	myKnobSlider1.setSliderStyle(Slider::RotaryVerticalDrag);
	myKnobSlider1.setTextBoxStyle(Slider::TextBoxBelow, false, 60, 20);

	addAndMakeVisible(myKnobSlider2);
	myKnobSlider2.setLookAndFeel(&myLookAndFeelV2);
	myKnobSlider2.setSliderStyle(Slider::RotaryVerticalDrag);
	myKnobSlider2.setTextBoxStyle(Slider::TextBoxBelow, false, 60, 20);

	addAndMakeVisible(myKnobSlider3);
	myKnobSlider3.setLookAndFeel(&myLookAndFeelV3);
	myKnobSlider3.setSliderStyle(Slider::RotaryVerticalDrag);
	myKnobSlider3.setTextBoxStyle(Slider::TextBoxBelow, false, 60, 20);
	
	setSize (600, 300);
	}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    	g.fillAll (Colours::black);
	g.setFont(Font(14.0f));
	g.setColour(Colours::grey);
	g.drawText("Search Path: " + File::getSpecialLocation(
			 File::SpecialLocationType::userDesktopDirectory)
			.getChildFile("knob1.png").getFullPathName(),
			 getLocalBounds().removeFromBottom(70), Justification::centred, true);

	g.drawText("Search Path: " + File::getSpecialLocation(
			 File::SpecialLocationType::userDesktopDirectory)
			.getChildFile("knob2.png").getFullPathName(),
			 getLocalBounds().removeFromBottom(100), Justification::centred, true);
	
	g.drawText("Resizable and FixedAspectRatio >>",	getLocalBounds()
			.removeFromBottom(20), Justification::right, true);
}

void MainContentComponent::resized()
{
	myKnobSlider1.setBoundsRelative(0.15, 0.2, 0.3, 0.3);
	myKnobSlider2.setBoundsRelative(0.35, 0.2, 0.3, 0.3);
	myKnobSlider3.setBoundsRelative(0.55, 0.2, 0.3, 0.3);
}
