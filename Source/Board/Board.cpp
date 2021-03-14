/*
  ==============================================================================

    Board.cpp
    Created: 20 Feb 2021 11:48:48am
    Author:  marcs

  ==============================================================================
*/

#include <JuceHeader.h>
#include "Board.h"
#include "../Pieces/Pieces.h"
#include "../Game.h"

//==============================================================================
Board::Board()
{

    // INIT SQUARES
    for (int i = 0; i < BOARD_LENGTH; i++)
    {
        Colour currentColour = (i & 0x01) ? Colour::WHITE : Colour::BLACK;
        for (int j = 0; j < BOARD_LENGTH; j++)
        {
            boardSquares.add( new Square(currentColour, Location((File)i, (Rank)j)));
            addAndMakeVisible(boardSquares.getLast());
            currentColour = currentColour == Colour::WHITE ? Colour::BLACK : Colour::WHITE;
        }
    }

    toBack();
}

void Board::initBoard()
{
    for (auto& s : boardSquares)
    {
        s->reset();
    }
}

Board::Board(const Board& other)
    : Board()
{

}

Board::~Board()
{

}

void Board::printBoard(void)
{
    for (int i = 0; i < boardSquares.size(); i++)
    {
        DBG(boardSquares[i]->toString());
    }
}

Square* Board::getSquare(Location l)
{
    return getSquare(l.getFile(), l.getRank());
}

Square* Board::getSquare(File f, Rank r)
{
    return boardSquares[(int)f * BOARD_LENGTH + (int)r];
}

void Board::paint (juce::Graphics& g)
{

}

void Board::addPieceToBoard(PieceBase* piece, Location l)
{
    addAndMakeVisible(piece);
    getSquare(l)->setCurrentPiece(piece);
}

void Board::resized()
{
    auto b = getLocalBounds();
    auto squareSize = std::min(b.getHeight(), b.getWidth()) / BOARD_LENGTH;
    for (int i = 0; i < BOARD_LENGTH; i++)
    {
        auto file = b.removeFromBottom(squareSize);
        for (int j = 0; j < BOARD_LENGTH; j++)
        {
            getSquare((File)j, (Rank)i)->setBounds(file.removeFromLeft(squareSize));
        }
    }
}

void Board::pieceMoving(PieceBase* piece)
{
    startDragging("PieceBase", piece);
    auto moves = piece->getValidMoves(this);
    for (auto& m : moves)
    {
        getSquare(m)->setTarget(true);
    }
}

void Board::noPieceMoving(void)
{
    for (auto& s : boardSquares)
    {
        s->setTarget(false);
    }
}

void Board::movePiece(PieceBase* piece, Square* square)
{
    piece->getCurrentSquare()->reset();
    square->setCurrentPiece(piece);

    auto pawn = dynamic_cast<Pawn*>(piece);
    if (pawn != nullptr)
    {
        pawn->makeFirstMove();
    }
}

int Board::getNumValidMoves(Colour player)
{
    juce::Array<Location> moves;

    for (auto& s : boardSquares)
    {
        auto p = s->getCurrentPiece();
        if (p != nullptr && p->getPieceColour() == player)
        {
            auto m = p->getValidMoves(this);
            moves.addArray(m);
        }
    }

    return moves.size();
}