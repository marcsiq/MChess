/*
  ==============================================================================

    Pawn.cpp
    Created: 20 Feb 2021 1:35:12pm
    Author:  marcs

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Pawn.h"
#include "../Board/Board.h"

//==============================================================================
Pawn::Pawn(Colour colour)
    :PieceBase("Pawn", colour)
{

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

juce::Array<Location> Pawn::getValidMoves(Board* board)
{
    auto current = getCurrentSquare()->getLocation();

    juce::Array<Location> moves;

    if (isVisible())
    {
        auto rank1Offset = getPieceColour() == Colour::WHITE ? 1 : -1;
        auto targetLocation = current.withOffset(0, rank1Offset);
        if (targetLocation.isValid() && !board->getSquare(targetLocation)->isOccupied())
        {
            moves.addIfNotAlreadyThere(targetLocation);
        }

        if (!hasMovedBefore())
        {

            auto rank2Offset = getPieceColour() == Colour::WHITE ? 2 : -2;
            targetLocation = current.withOffset(0, rank2Offset);
            if (targetLocation.isValid() && !board->getSquare(targetLocation)->isOccupied())
            {
                moves.addIfNotAlreadyThere(current.withOffset(0, rank2Offset));
            }
        }

        targetLocation = current.withOffset(1, rank1Offset);
        if (targetLocation.isValid())
        {
            auto targetSquare = board->getSquare(targetLocation);
            if (targetSquare->isOccupied() && targetSquare->getCurrentPiece()->getPieceColour() != getPieceColour())
            {
                moves.addIfNotAlreadyThere(targetLocation);
            }
        }

        targetLocation = current.withOffset(-1, rank1Offset);
        if (targetLocation.isValid())
        {
            auto targetSquare = board->getSquare(targetLocation);
            if (targetSquare->isOccupied() && targetSquare->getCurrentPiece()->getPieceColour() != getPieceColour())
            {
                moves.addIfNotAlreadyThere(targetLocation);
            }
        }
    }
    return moves;
}
