/*
  ==============================================================================

    Queen.h
    Created: 20 Feb 2021 1:35:12pm
    Author:  marcs

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PieceBase.h"
#include "../Board/Moves.h"

//==============================================================================
/*
*/
class Queen  : public PieceBase,
               public Moves
{
public:
    Queen(Colour colour);
    ~Queen() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    juce::Array<Location> getValidMoves(Board board) override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Queen)
};