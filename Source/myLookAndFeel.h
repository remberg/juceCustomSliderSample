
/*
  ==============================================================================

    Created: 14 Dec 2017 10:16:04am
    Author:  Stefan Remberg

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

#pragma region myLookAndFeelV1
class myLookAndFeelV1 : public LookAndFeel_V4
{
public:
	myLookAndFeelV1();

	void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
		float rotaryStartAngle, float rotaryEndAngle, Slider& slider) override;

};
#pragma endregion

#pragma region myLookAndFeelV2
class myLookAndFeelV2 : public LookAndFeel_V4
{
public:
	myLookAndFeelV2();

	void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
		float rotaryStartAngle, float rotaryEndAngle, Slider& slider) override;

};
#pragma endregion

#pragma region myLookAndFeelV3
class myLookAndFeelV3 : public LookAndFeel_V4
{
public:
	myLookAndFeelV3();

	void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
		float rotaryStartAngle, float rotaryEndAngle, Slider& slider) override;

};
#pragma endregion