/*
  ==============================================================================

    Bishop.h
    Created: 20 Feb 2021 1:35:12pm
    Author:  marcs

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PieceBase.h"

//==============================================================================
/*
*/
class Bishop  : public PieceBase
{
public:
    Bishop(Colour colour);
    ~Bishop() override;

    juce::Array<Location> getValidMoves(Board* board) override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Bishop)
};
