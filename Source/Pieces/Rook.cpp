/*
  ==============================================================================

    Rook.cpp
    Created: 20 Feb 2021 1:35:12pm
    Author:  marcs

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Rook.h"
#include "../Board/Board.h"

//==============================================================================
Rook::Rook(Colour colour)
    :PieceBase("Rook", colour)
{
    if (colour == Colour::BLACK)
    {
        pieceImg = juce::ImageCache::getFromMemory(BinaryData::br_png, BinaryData::br_pngSize);
    }
    else if (colour == Colour::WHITE)
    {
        pieceImg = juce::ImageCache::getFromMemory(BinaryData::wr_png, BinaryData::wr_pngSize);
    }
}

Rook::~Rook()
{
}

juce::Array<Location> Rook::getValidMoves(Board* board)
{
    juce::Array<Location> moves;
    return moves;
}
