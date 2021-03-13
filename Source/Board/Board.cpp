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
            currentColour = currentColour == Colour::WHITE ? Colour::BLACK : Colour::WHITE;
        }
    }

    for (auto& s : boardSquares)
    {
        addAndMakeVisible(s);
    }

    // INIT PIECES
    for (int c = 0; c < 2; c++)
    {
        auto colour = c == 0 ? Colour::WHITE : Colour::BLACK;
        for (int i = 0; i < 2; i++)
        {
            pieces.rook[c][i].reset(new Rook(colour));
            addAndMakeVisible(pieces.rook[c][i].get());
            pieces.knight[c][i].reset(new Knight(colour));
            addAndMakeVisible(pieces.knight[c][i].get());
            pieces.bishop[c][i].reset(new Bishop(colour));
            addAndMakeVisible(pieces.bishop[c][i].get());
        }

        for (int i = 0; i < 8; i++)
        {
            pieces.pawn[c][i].reset(new Pawn(colour));
            addAndMakeVisible(pieces.pawn[c][i].get());
        }


        pieces.king[c].reset(new King(colour));
        addAndMakeVisible(pieces.king[c].get());
        pieces.queen[c].reset(new Queen(colour));
        addAndMakeVisible(pieces.queen[c].get());
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

void Board::startGame()
{
    initBoard();
    currentPlayer = Colour::WHITE;

    getSquare(File::A, Rank::_1)->setCurrentPiece(pieces.rook[(int)Colour::WHITE][0].get());
    getSquare(File::H, Rank::_1)->setCurrentPiece(pieces.rook[(int)Colour::WHITE][1].get());
    getSquare(File::A, Rank::_8)->setCurrentPiece(pieces.rook[(int)Colour::BLACK][0].get());
    getSquare(File::H, Rank::_8)->setCurrentPiece(pieces.rook[(int)Colour::BLACK][1].get());
    
    getSquare(File::C, Rank::_1)->setCurrentPiece(pieces.bishop[(int)Colour::WHITE][0].get());
    getSquare(File::F, Rank::_1)->setCurrentPiece(pieces.bishop[(int)Colour::WHITE][1].get());
    getSquare(File::C, Rank::_8)->setCurrentPiece(pieces.bishop[(int)Colour::BLACK][0].get());
    getSquare(File::F, Rank::_8)->setCurrentPiece(pieces.bishop[(int)Colour::BLACK][1].get());

    getSquare(File::B, Rank::_1)->setCurrentPiece(pieces.knight[(int)Colour::WHITE][0].get());
    getSquare(File::G, Rank::_1)->setCurrentPiece(pieces.knight[(int)Colour::WHITE][1].get());
    getSquare(File::B, Rank::_8)->setCurrentPiece(pieces.knight[(int)Colour::BLACK][0].get());
    getSquare(File::G, Rank::_8)->setCurrentPiece(pieces.knight[(int)Colour::BLACK][1].get());

    getSquare(File::D, Rank::_1)->setCurrentPiece(pieces.queen[(int)Colour::WHITE].get());
    getSquare(File::D, Rank::_8)->setCurrentPiece(pieces.queen[(int)Colour::BLACK].get());

    getSquare(File::E, Rank::_1)->setCurrentPiece(pieces.king[(int)Colour::WHITE].get());
    getSquare(File::E, Rank::_8)->setCurrentPiece(pieces.king[(int)Colour::BLACK].get());

    for (int i = 0; i < 8; i++)
    {
        getSquare((File)i, Rank::_2)->setCurrentPiece(pieces.pawn[(int)Colour::WHITE][i].get());
        getSquare((File)i, Rank::_7)->setCurrentPiece(pieces.pawn[(int)Colour::BLACK][i].get());
    }

}

Board::Board(const Board& other)
    : Board()
{

}

Board::~Board()
{
    for (int c = 0; c < 2; c++)
    {
        for (int i = 0; i < 2; i++)
        {
            pieces.rook[c][i] = nullptr;
            pieces.knight[c][i] = nullptr;
            pieces.bishop[c][i] = nullptr;
        }

        for (int i = 0; i < 8; i++)
        {
            pieces.pawn[c][i] = nullptr;
        }

        pieces.king[c] = nullptr;
        pieces.queen[c] = nullptr;
    }
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

Colour Board::getCurrentPlayer()
{
    return currentPlayer;
}

void Board::nextPlayer()
{
    currentPlayer = currentPlayer == Colour::WHITE ? Colour::BLACK : Colour::WHITE;
}