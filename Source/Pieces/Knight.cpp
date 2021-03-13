/*
  ==============================================================================

    Knight.cpp
    Created: 20 Feb 2021 1:35:12pm
    Author:  marcs

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Knight.h"
#include "../Board/Board.h"

//==============================================================================
Knight::Knight(Colour colour)
    :PieceBase("Knight", colour)
{
    if (colour == Colour::BLACK)
    {
        pieceImg = juce::ImageCache::getFromMemory(BinaryData::bn_png, BinaryData::bn_pngSize);
    }
    else if (colour == Colour::WHITE)
    {
        pieceImg = juce::ImageCache::getFromMemory(BinaryData::wn_png, BinaryData::wn_pngSize);
    }
}

Knight::~Knight()
{
}

juce::Array<Location> Knight::getValidMoves(Board* board)
{
    juce::Array<Location> moves;
    return moves;
}
