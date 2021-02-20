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
#include "../Pieces/Pieces.h"
//==============================================================================
/*
*/
class Board  : public juce::Component
{
public:
    Board();
    ~Board() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void printBoard(void);
    void printPiece(PieceBase piece);

    Square* getSquare(File f, Rank r);
private:


    juce::OwnedArray<Square> boardSquares;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Board)
};
