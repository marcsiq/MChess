/*
  ==============================================================================

    Pawn.h
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
class Pawn  : public PieceBase,
            public Moves
{
public:
    Pawn(Colour colour);
    ~Pawn() override;

    juce::Array<Location> getValidMoves(Board board) override;

private:
    bool isFirstMove;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Pawn)
};
