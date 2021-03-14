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
    auto current = currentSquare->getLocation();
    juce::Array<Location> moves;
    Location targetLocation(File::A, Rank::_1);
    Square* targetSquare;

    int offset = 0;
    
    while (true)
    {
        targetLocation = current.withOffset(--offset, 0);
        targetSquare = board->getSquare(targetLocation);

        if (!targetLocation.isValid())
        {
            break;
        }
        else if (!targetSquare->isOccupied())
        {
            moves.add(targetLocation);
        }
        else if (targetSquare->getCurrentPiece()->getPieceColour() != getPieceColour())
        {
            moves.add(targetLocation);
            break;
        }
        else
        {
            break;
        }
    }

    offset = 0;

    while (true)
    {
        targetLocation = current.withOffset(++offset, 0);
        targetSquare = board->getSquare(targetLocation);

        if (!targetLocation.isValid())
        {
            break;
        }
        else if (!targetSquare->isOccupied())
        {
            moves.add(targetLocation);
        }
        else if (targetSquare->getCurrentPiece()->getPieceColour() != getPieceColour())
        {
            moves.add(targetLocation);
            break;
        }
        else
        {
            break;
        }
    }

    offset = 0;

    while (true)
    {
        targetLocation = current.withOffset(0, --offset);
        targetSquare = board->getSquare(targetLocation);

        if (!targetLocation.isValid())
        {
            break;
        }
        else if (!targetSquare->isOccupied())
        {
            moves.add(targetLocation);
        }
        else if (targetSquare->getCurrentPiece()->getPieceColour() != getPieceColour())
        {
            moves.add(targetLocation);
            break;
        }
        else
        {
            break;
        }
    }

    offset = 0;

    while (true)
    {
        targetLocation = current.withOffset(0, ++offset);
        targetSquare = board->getSquare(targetLocation);

        if (!targetLocation.isValid())
        {
            break;
        }
        else if (!targetSquare->isOccupied())
        {
            moves.add(targetLocation);
        }
        else if (targetSquare->getCurrentPiece()->getPieceColour() != getPieceColour())
        {
            moves.add(targetLocation);
            break;
        }
        else
        {
            break;
        }
    }

    return moves;
}
