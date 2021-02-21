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
    for (auto& s : boardSquares)
    {
        DBG(s->toString());
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
