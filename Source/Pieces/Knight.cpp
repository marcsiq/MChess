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

static const int KnightValue = 3;

Knight::Knight(Colour colour)
	:PieceBase("Knight", colour, KnightValue)
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

juce::Array<Location> Knight::getValidMoves(const Board& board)
{
	juce::Array<Location> moves;
	auto current = getCurrentSquare()->getLocation();

	auto targetLocation = current.withOffset(2, -1);
	auto targetSquare = board.getSquare(targetLocation);
	if (targetLocation.isValid() && (!targetSquare->isOccupied() || targetSquare->getCurrentPiece()->getPieceColour() != getPieceColour()))
	{
		moves.add(targetLocation);
	}

	targetLocation = current.withOffset(2, 1);
	targetSquare = board.getSquare(targetLocation);
	if (targetLocation.isValid() && (!targetSquare->isOccupied() || targetSquare->getCurrentPiece()->getPieceColour() != getPieceColour()))
	{
		moves.add(targetLocation);
	}

	targetLocation = current.withOffset(-2, -1);
	targetSquare = board.getSquare(targetLocation);
	if (targetLocation.isValid() && (!targetSquare->isOccupied() || targetSquare->getCurrentPiece()->getPieceColour() != getPieceColour()))
	{
		moves.add(targetLocation);
	}

	targetLocation = current.withOffset(-2, 1);
	targetSquare = board.getSquare(targetLocation);
	if (targetLocation.isValid() && (!targetSquare->isOccupied() || targetSquare->getCurrentPiece()->getPieceColour() != getPieceColour()))
	{
		moves.add(targetLocation);
	}

	targetLocation = current.withOffset(1, 2);
	targetSquare = board.getSquare(targetLocation);
	if (targetLocation.isValid() && (!targetSquare->isOccupied() || targetSquare->getCurrentPiece()->getPieceColour() != getPieceColour()))
	{
		moves.add(targetLocation);
	}

	targetLocation = current.withOffset(-1, 2);
	targetSquare = board.getSquare(targetLocation);
	if (targetLocation.isValid() && (!targetSquare->isOccupied() || targetSquare->getCurrentPiece()->getPieceColour() != getPieceColour()))
	{
		moves.add(targetLocation);
	}

	targetLocation = current.withOffset(1, -2);
	targetSquare = board.getSquare(targetLocation);
	if (targetLocation.isValid() && (!targetSquare->isOccupied() || targetSquare->getCurrentPiece()->getPieceColour() != getPieceColour()))
	{
		moves.add(targetLocation);
	}

	targetLocation = current.withOffset(-1, -2);
	targetSquare = board.getSquare(targetLocation);
	if (targetLocation.isValid() && (!targetSquare->isOccupied() || targetSquare->getCurrentPiece()->getPieceColour() != getPieceColour()))
	{
		moves.add(targetLocation);
	}

	return moves;
}