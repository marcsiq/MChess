#pragma once

#include <JuceHeader.h>
#include "Board/Board.h"
//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class Game 
{
public:
    //==============================================================================
    Game(Board* mBoard);
    ~Game();

    void startGame();
    void nextPlayer();

private:
    //==============================================================================
    // Your private member variables go here...
    std::unique_ptr<Board> board;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Game)
};

/**
* @brief     Returns a Pointer to our MChessApplication game
*/
Game* getGame();