/*
  ==============================================================================

	Bishop.cpp
	Created: 20 Feb 2021 1:35:12pm
	Author:  marcs

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Bishop.h"
#include "../Board/Board.h"

//==============================================================================

static const int BishopValue = 3;

Bishop::Bishop(Colour colour)
	:PieceBase("Bishop", colour, BishopValue)
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

juce::Array<Location> Bishop::getValidMoves(const Board& board)
{
	auto current = currentSquare->getLocation();
	juce::Array<Location> moves;
	Location targetLocation(File::A, Rank::_1);
	Square* targetSquare;

	int offset = 0;

	while (true)
	{
		--offset;
		targetLocation = current.withOffset(offset, offset);
		targetSquare = board.getSquare(targetLocation);

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
		++offset;
		targetLocation = current.withOffset(offset, offset);
		targetSquare = board.getSquare(targetLocation);

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
		--offset;
		targetLocation = current.withOffset(-offset, offset);
		targetSquare = board.getSquare(targetLocation);

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
		--offset;
		targetLocation = current.withOffset(offset, -offset);
		targetSquare = board.getSquare(targetLocation);

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