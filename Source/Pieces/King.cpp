/*
  ==============================================================================

    King.cpp
    Created: 20 Feb 2021 1:35:12pm
    Author:  marcs

  ==============================================================================
*/

#include <JuceHeader.h>
#include "King.h"

//==============================================================================
King::King(Colour colour)
    :PieceBase("King", colour)
{
    if (colour == Colour::BLACK)
    {
        pieceImg = juce::ImageCache::getFromMemory(BinaryData::bk_png, BinaryData::bk_pngSize);
    }
    else if (colour == Colour::WHITE)
    {
        pieceImg = juce::ImageCache::getFromMemory(BinaryData::wk_png, BinaryData::wk_pngSize);
    }
}

King::~King()
{
}

juce::Array<Location> King::getValidMoves(Board board)
{
    juce::Array<Location> moves;
    auto current = currentSquare->getLocation();
    moves.add(currentSquare->getLocation());
    return moves;
}
