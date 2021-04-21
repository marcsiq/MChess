/*
  ==============================================================================

	Application.h
	Created: 13 Mar 2021 11:58:44am
	Author:  marcs

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "Game.h"

//==============================================================================
class MChessApplication : public juce::JUCEApplication
{
public:
	//==============================================================================
	MChessApplication() {}

	const juce::String getApplicationName() override { return ProjectInfo::projectName; }
	const juce::String getApplicationVersion() override { return ProjectInfo::versionString; }
	bool moreThanOneInstanceAllowed() override { return true; }

	static MChessApplication& getApp()
	{
		MChessApplication* const app = dynamic_cast<MChessApplication*> (JUCEApplication::getInstance());
		jassert(app != nullptr);
		return *app;
	}

	//==============================================================================
	void initialise(const juce::String&) override
	{
		board.reset(new Board());
		game.reset(new Game(board));
		mainWindow.reset(new MainWindow(getApplicationName(), board.get()));
	}

	void shutdown() override
	{
		board = nullptr;
		game = nullptr;
		mainWindow = nullptr; // (deletes our window)
	}

	Game* getGame()
	{
		return game.get();
	}

	//==============================================================================
	void systemRequestedQuit() override
	{
		// This is called when the app is being asked to quit: you can ignore this
		// request and let the app carry on running, or call quit() to allow the app to close.
		quit();
	}

	void anotherInstanceStarted(const juce::String&) override
	{
		// When another instance of the app is launched while this one is running,
		// this method is invoked, and the commandLine parameter tells you what
		// the other instance's command-line arguments were.
	}

	//==============================================================================
	/*
		This class implements the desktop window that contains an instance of
		our MainComponent class.
	*/
	class MainWindow : public juce::DocumentWindow
	{
	public:
		MainWindow(juce::String name, Board* board)
			: DocumentWindow(name,
				juce::Desktop::getInstance().getDefaultLookAndFeel()
				.findColour(juce::ResizableWindow::backgroundColourId),
				DocumentWindow::allButtons)
		{
			board->setSize(800, 800);
			setUsingNativeTitleBar(true);
			setContentOwned(board, true);

			setResizable(false, false);
			centreWithSize(getWidth(), getHeight());
			setVisible(true);
		}

		void closeButtonPressed() override
		{
			// This is called when the user tries to close this window. Here, we'll just
			// ask the app to quit when this happens, but you can change this to do
			// whatever you need.
			JUCEApplication::getInstance()->systemRequestedQuit();
		}

	private:
		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainWindow)
	};

private:
	std::unique_ptr<Game> game;
	std::unique_ptr<MainWindow> mainWindow;
	std::shared_ptr<Board> board;
};