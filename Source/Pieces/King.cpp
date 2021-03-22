/*
  ==============================================================================

	King.cpp
	Created: 20 Feb 2021 1:35:12pm
	Author:  marcs

  ==============================================================================
*/

#include <JuceHeader.h>
#include "King.h"
#include "../Board/Board.h"

//==============================================================================

static const int KingValue = 100;

King::King(Colour colour)
	:PieceBase("King", colour, KingValue)
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

juce::Array<Location> King::getValidMoves(const Board& board)
{
	juce::Array<Location> moves;
	auto current = currentSquare->getLocation();

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			const auto& targetLocation = current.withOffset(i, j);
			if (targetLocation.isValid())
			{
				if (!board.getSquare(targetLocation)->isOccupied())
				{
					moves.addIfNotAlreadyThere(targetLocation);
				}
				else if (board.getSquare(targetLocation)->getCurrentPiece()->getPieceColour() != getPieceColour())
				{
					moves.addIfNotAlreadyThere(targetLocation);
				}
			}
		}
	}
	return moves;
}