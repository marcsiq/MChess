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
#include "../Pieces/Bishop.h"
#include "../Pieces/Rook.h"

//==============================================================================

static const int QueenValue = 9;

Queen::Queen(Colour colour)
	:PieceBase("Queen", colour, QueenValue)
{
	if (colour == Colour::BLACK)
	{
		pieceImg = juce::ImageCache::getFromMemory(BinaryData::bq_png, BinaryData::bq_pngSize);
	}
	else if (colour == Colour::WHITE)
	{
		pieceImg = juce::ImageCache::getFromMemory(BinaryData::wq_png, BinaryData::wq_pngSize);
	}
	rook.reset(new Rook(colour));
	bishop.reset(new Bishop(colour));
}

Queen::~Queen()
{
	rook = nullptr;
	rook = nullptr;
}

juce::Array<Location> Queen::getValidMoves(const Board& board)
{
	juce::Array<Location> moves;
	rook->setStartingSquare(currentSquare);
	bishop->setStartingSquare(currentSquare);

	moves.addArray(rook->getValidMoves(board));
	moves.addArray(bishop->getValidMoves(board));

	return moves;
}