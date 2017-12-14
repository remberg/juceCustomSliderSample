/*
  ==============================================================================

    RBBinary.h
    Created: 6 Nov 2017 6:00:40pm
    Author:  Stefan Remberg

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
class RBBinary : public Component

{
public:
	
	RBBinary(RBToneGenAudioProcessor& processor);
	~RBBinary();

	void paint(Graphics& g) override;
	void resized() override;

private:
	ScopedPointer<ImageButton> imageButton;

	RBToneGenAudioProcessor& processor;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RBBinary)
};
