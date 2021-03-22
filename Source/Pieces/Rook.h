/*
  ==============================================================================

	Rook.h
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
class Rook : public PieceBase
{
public:
	Rook(Colour colour);

	juce::Array<Location> getValidMoves(const Board& board) override;

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Rook)
};
