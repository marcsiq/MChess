/*
  ==============================================================================

    Moves.h
    Created: 20 Feb 2021 3:56:10pm
    Author:  marcs

  ==============================================================================
*/

#pragma once
#include "Board.h"

class Moves
{
public:
    virtual juce::Array<Location> getValidMoves(Board board)
    {
        juce::Array<Location> moves;
        return moves;
    }

    virtual juce::Array<Location> getValidMoves(Board board, Square square)
    {
        juce::Array<Location> moves;
        return moves;
    }
};