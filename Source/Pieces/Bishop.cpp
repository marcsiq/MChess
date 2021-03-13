/*
  ==============================================================================

    Bishop.cpp
    Created: 20 Feb 2021 1:35:12pm
    Author:  marcs

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Bishop.h"

//==============================================================================
Bishop::Bishop(Colour colour)
    :PieceBase("Bishop", colour)
{
    if (colour == Colour::BLACK)
    {
        pieceImg = juce::ImageCache::getFromMemory(BinaryData::bb_png, BinaryData::bb_pngSize);
    }
    else if (colour == Colour::WHITE)
    {
        pieceImg = juce::ImageCache::getFromMemory(BinaryData::wb_png, BinaryData::wb_pngSize);
    }
}

Bishop::~Bishop()
{
}

juce::Array<Location> Bishop::getValidMoves(Board board)
{
    juce::Array<Location> moves;
    return moves;
}
