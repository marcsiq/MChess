/*
  ==============================================================================

    Board.h
    Created: 20 Feb 2021 11:48:48am
    Author:  marcs

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Square.h"
#include "../Pieces/PieceBase.h"

//==============================================================================
/*
*/
class Board  : public juce::Component
{
public:
    Board();
    ~Board() override;
    Board(const Board& other);

    void initBoard();

    void paint (juce::Graphics&) override;
    void resized() override;

    void printBoard(void);

    Square* getSquare(File f, Rank r);
    Square* getSquare(Location l);
private:

    juce::OwnedArray<Square> boardSquares;

    JUCE_LEAK_DETECTOR(Board)
};
