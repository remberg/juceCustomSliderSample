
/*
  ==============================================================================

    Created: 14 Dec 2017 10:16:04am
    Author:  Stefan Remberg

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"

//==============================================================================
class PNG_KnobSampleApplication : public JUCEApplication
{
public:
	//==============================================================================
	PNG_KnobSampleApplication() {}

	const String getApplicationName() override { return ProjectInfo::projectName; }
	const String getApplicationVersion() override { return ProjectInfo::versionString; }
	bool moreThanOneInstanceAllowed() override { return true; }

	//==============================================================================
	void initialise(const String& commandLine) override
	{
		mainWindow = new MainWindow(getApplicationName());
	}

	void shutdown() override
	{
		mainWindow = nullptr;
	}

	//==============================================================================
	void systemRequestedQuit() override
	{
		quit();
	}

	void anotherInstanceStarted(const String& commandLine) override
	{

	}

	//==============================================================================

	class MainWindow : public DocumentWindow
	{
	public:
		MainWindow(String name) : DocumentWindow(name,
			Desktop::getInstance().getDefaultLookAndFeel()
			.findColour(ResizableWindow::backgroundColourId),
			DocumentWindow::allButtons)
		{
			setUsingNativeTitleBar(true);
			setContentOwned(new MainContentComponent(), true);
			centreWithSize(getWidth(), getHeight());
			
			
			//make the windows resizable
			setResizable(true, true);
			//only resizable withe fixed ratio
			getConstrainer()->setFixedAspectRatio(2);
			//set the resizable limits
			setResizeLimits(400, 200, 1000, 500);
			


			setVisible(true);
		}

		void closeButtonPressed() override
		{
			JUCEApplication::getInstance()->systemRequestedQuit();
		}

	private:
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainWindow)
	};

private:
	ScopedPointer<MainWindow> mainWindow;
};

//==============================================================================
START_JUCE_APPLICATION(PNG_KnobSampleApplication)
