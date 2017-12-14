/*
  ==============================================================================

    RBBinary.cpp
    Created: 6 Nov 2017 6:00:40pm
    Author:  Stefan Remberg

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "RBBinary.h"

RBBinary::RBBinary(RBToneGenAudioProcessor& processor) : processor(processor)
{
	addAndMakeVisible(imageButton = new ImageButton("new button"));
	imageButton->setImages(false, true, true,
		ImageCache::getFromMemory(BinaryData::remberg_png, BinaryData::remberg_pngSize), 1.000f, Colour(0x888abeff),
		ImageCache::getFromMemory(BinaryData::remberg_png, BinaryData::remberg_pngSize), 1.000f, Colours::white,
		ImageCache::getFromMemory(BinaryData::remberg_png, BinaryData::remberg_pngSize), 1.000f, Colour(0x888abeff));
}

RBBinary::~RBBinary()
{
	imageButton = nullptr;
}
void RBBinary::paint(Graphics& g)
{
	//[UserPrePaint] Add your own custom painting code here..
	//[/UserPrePaint]

	g.fillAll(Colour(0xff323e44));

	//[UserPaint] Add your own custom painting code here..
	//[/UserPaint]
}

void RBBinary::resized()
{
	imageButton->setBounds(144, 92, 944, 509);
}



