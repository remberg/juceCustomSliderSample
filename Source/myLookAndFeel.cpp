
/*
  ==============================================================================

    Created: 14 Dec 2017 10:16:04am
    Author:  Stefan Remberg

  ==============================================================================
*/

#include "myLookAndFeel.h"

#pragma region myLookAndFeelV1
myLookAndFeelV1::myLookAndFeelV1()
{
	setColourScheme(LookAndFeel_V4::getDarkColourScheme());
}

void myLookAndFeelV1::drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
	float rotaryStartAngle, float rotaryEndAngle, Slider& slider)
{
	File knobFile = File::getSpecialLocation(File::SpecialLocationType::userDesktopDirectory).getChildFile("knob1.png");
	if (knobFile.exists()) {
		Image myKnobStrip = ImageFileFormat::loadFrom(knobFile);
		const double rotation = (slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum());
		const int frames = myKnobStrip.getHeight() / myKnobStrip.getWidth();
		const int frameId = (int)ceil(rotation * ((double)frames - 1.0));
		const float radius = jmin(width / 2.0f, height / 2.0f);
		const float centerX = x + width * 0.5f;
		const float centerY = y + height * 0.5f;
		const float rx = centerX - radius - 1.0f;
		const float ry = centerY - radius;

		g.drawImage(myKnobStrip,
			(int)rx,
			(int)ry,
			2 * (int)radius,
			2 * (int)radius,
			0,
			frameId*myKnobStrip.getWidth(),
			myKnobStrip.getWidth(),
			myKnobStrip.getWidth());
	}
	else
	{
		static const float TEXT_W_PERCENT = 0.35f;
		Rectangle<float> text_bounds(1.0f + width * (1.0f - TEXT_W_PERCENT) / 2.0f,
			0.5f * height, width * TEXT_W_PERCENT, 0.5f * height);

		g.setColour(Colours::white);

		g.drawFittedText(String("No Image"), text_bounds.getSmallestIntegerContainer(),
			Justification::horizontallyCentred | Justification::centred, 1);
	}
}
#pragma endregion

#pragma region myLookAndFeelV2
myLookAndFeelV2::myLookAndFeelV2()
{
	setColourScheme(LookAndFeel_V4::getDarkColourScheme());
	setColour(Slider::rotarySliderFillColourId, Colours::white);
}

void myLookAndFeelV2::drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
	float rotaryStartAngle, float rotaryEndAngle, Slider& slider)
{
	const float radius = jmin(width / 2, height / 2) *0.85f;
	const float centreX = x + width * 0.5f;
	const float centreY = y + height * 0.5f;
	const float rx = centreX - radius;
	const float ry = centreY - radius;
	const float rw = radius * 2.0f;
	float fwidth = (float)width;
	float fheight = (float)height;
	const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);

	g.setColour(Colour(0xff39587a));
	Path filledArc;
	filledArc.addPieSegment(rx, ry, rw + 1, rw + 1, rotaryStartAngle, rotaryEndAngle, 0.6);

	g.fillPath(filledArc);

	g.setColour(Colours::lightgreen);
	Path filledArc1;
	filledArc1.addPieSegment(rx, ry, rw + 1, rw + 1, rotaryStartAngle, angle, 0.6);

	g.fillPath(filledArc1);

	Path p;
	const float pointerLength = radius * 0.63f;
	const float pointerThickness = radius *0.2f;
	p.addRectangle(-pointerThickness * 0.5f, -radius - 1, pointerThickness, pointerLength);
	p.applyTransform(AffineTransform::rotation(angle).translated(centreX, centreY));
	g.setColour(Colour(0xff39587a));
	g.fillPath(p);

	const float dotradius = radius * (float)0.4;
	const float dotradius2 = rw * (float)0.4;
	g.setColour(Colour(0xff39587a));
	g.fillEllipse(centreX - (dotradius), centreY - (dotradius), dotradius2, dotradius2);
}
#pragma endregion

#pragma region myLookAndFeelV3
myLookAndFeelV3::myLookAndFeelV3()
{
	setColourScheme(LookAndFeel_V4::getDarkColourScheme());
	setColour(Slider::rotarySliderFillColourId, Colours::white);
}

void myLookAndFeelV3::drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
	float rotaryStartAngle, float rotaryEndAngle, Slider& slider)
{
	File knobFile = File::getSpecialLocation(File::SpecialLocationType::userDesktopDirectory).getChildFile("knob2.png");
	if (knobFile.exists()) {
		Image myKnobStrip = ImageFileFormat::loadFrom(knobFile);
		const double rotation = (slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum());
		const int frames = myKnobStrip.getHeight() / myKnobStrip.getWidth();
		const int frameId = (int)ceil(rotation * ((double)frames - 1.0));
		const float radius = jmin(width / 2.0f, height / 2.0f);
		const float centerX = x + width * 0.5f;
		const float centerY = y + height * 0.5f;
		const float rx = centerX - radius - 1.0f;
		const float ry = centerY - radius;

		g.drawImage(myKnobStrip,
			(int)rx,
			(int)ry,
			2 * (int)radius,
			2 * (int)radius,
			0,
			frameId*myKnobStrip.getWidth(),
			myKnobStrip.getWidth(),
			myKnobStrip.getWidth());
	}
	else
	{
		static const float TEXT_W_PERCENT = 0.35f;
		Rectangle<float> text_bounds(1.0f + width * (1.0f - TEXT_W_PERCENT) / 2.0f,
			0.5f * height, width * TEXT_W_PERCENT, 0.5f * height);

		g.setColour(Colours::white);

		g.drawFittedText(String("No Image"), text_bounds.getSmallestIntegerContainer(),
			Justification::horizontallyCentred | Justification::centred, 1);
	}
}
#pragma endregion