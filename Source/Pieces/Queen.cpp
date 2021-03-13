/*
  ==============================================================================

    Queen.cpp
    Created: 20 Feb 2021 1:35:12pm
    Author:  marcs

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Queen.h"
#include "../Board/Board.h"

//==============================================================================
Queen::Queen(Colour colour)
    :PieceBase("Queen", colour)
{
    if (colour == Colour::BLACK)
    {
        pieceImg = juce::ImageCache::getFromMemory(BinaryData::bq_png, BinaryData::bq_pngSize);
    }
    else if (colour == Colour::WHITE)
    {
        pieceImg = juce::ImageCache::getFromMemory(BinaryData::wq_png, BinaryData::wq_pngSize);
    }
}

Queen::~Queen()
{
}

juce::Array<Location> Queen::getValidMoves(Board* board)
{
    juce::Array<Location> moves;
    return moves;
}
