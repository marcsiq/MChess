/*
  ==============================================================================

    Pawn.cpp
    Created: 20 Feb 2021 1:35:12pm
    Author:  marcs

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Pawn.h"

//==============================================================================
Pawn::Pawn(Colour colour)
    :PieceBase("Pawn", colour)
{
    isFirstMove = true;

    if (colour == Colour::BLACK)
    {
        pieceImg = juce::ImageCache::getFromMemory(BinaryData::bp_png, BinaryData::bp_pngSize);
    }
    else if (colour == Colour::WHITE)
    {
        pieceImg = juce::ImageCache::getFromMemory(BinaryData::wp_png, BinaryData::wp_pngSize);
    }
}

Pawn::~Pawn()
{
}

juce::Array<Location> Pawn::getValidMoves(Board board)
{
    auto current = getCurrentSquare()->getLocation();
    juce::Array<Location> moves;
    return moves;
}
