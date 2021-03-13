/*
  ==============================================================================

    Board.h
    Created: 20 Feb 2021 11:48:48am
    Author:  marcs

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Square.h"
#include "../Pieces/PieceBase.h"

//==============================================================================
/*
*/
class Board  : public juce::Component,
    public juce::DragAndDropContainer
{
public:
    Board();
    ~Board() override;
    Board(const Board& other);

    void initBoard();
    void startGame();

    void paint (juce::Graphics&) override;
    void resized() override;

    void printBoard(void);

    Colour getCurrentPlayer();
    void nextPlayer();

    Square* getSquare(File f, Rank r);
    Square* getSquare(Location l);

    void pieceMoving(PieceBase* piece);
    void movePiece(PieceBase* piece, Square* square);

    void noPieceMoving(void);

    int getNumValidMoves(void);

private:

    juce::OwnedArray<Square> boardSquares;

    struct
    {
        std::unique_ptr<PieceBase> queen[2];
        std::unique_ptr<PieceBase> king[2];
        std::unique_ptr<PieceBase> pawn[2][8];
        std::unique_ptr<PieceBase> rook[2][2];
        std::unique_ptr<PieceBase> bishop[2][2];
        std::unique_ptr<PieceBase> knight[2][2];
    }pieces;

    Colour currentPlayer;

    JUCE_LEAK_DETECTOR(Board)
};
