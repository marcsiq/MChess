#include "Game.h"
#include "Application.h"
#include "Pieces/Pieces.h"

Game* getGame()
{
    return MChessApplication::getApp().getGame();
}

//==============================================================================
Game::Game(Board* mBoard)
{
    board.reset(mBoard);
    initPieceSet(&blackPieces, Colour::BLACK);
    initPieceSet(&whitePieces, Colour::WHITE);
    startGame();
}

Game::~Game()
{
    board.release();

}

void Game::startGame()
{
    board->initBoard();
    placeStartingPieces();
    currentPlayer = Colour::WHITE;

    printValidMovesForCurrentPlayer();
}

void Game::nextPlayer()
{
    currentPlayer = (currentPlayer == Colour::WHITE ? Colour::BLACK : Colour::WHITE);
    printValidMovesForCurrentPlayer();
}

Colour Game::getCurrentPlayer()
{
    return currentPlayer;
}

void Game::makeMove(PieceBase* piece, Square* square)
{
    board->movePiece(piece, square);
    nextPlayer();
}

Board* Game::getBoard()
{
    return board.get();
}

void Game::printValidMovesForCurrentPlayer()
{
    DBG("NUM VALID MOVES FOR " << colourToString[currentPlayer] << " --> " << board->getNumValidMoves(currentPlayer));

}

void Game::initPieceSet(PieceSet* set, Colour colour)
{
    set->rook[0].reset(new Rook(colour));
    set->rook[1].reset(new Rook(colour));

    set->knight[0].reset(new Knight(colour));
    set->knight[1].reset(new Knight(colour));

    set->bishop[0].reset(new Bishop(colour));
    set->bishop[1].reset(new Bishop(colour));

    set->king.reset(new King(colour));
    set->queen.reset(new Queen(colour));

    for (int i = 0; i < 8; i++)
    {
        set->pawn[i].reset(new Pawn(colour));

    }

}

void Game::placeStartingPieces()
{
    board->addPieceToBoard(whitePieces.rook[0].get(), { File::A, Rank::_1 });
    board->addPieceToBoard(whitePieces.rook[1].get(), { File::H, Rank::_1});

    board->addPieceToBoard(blackPieces.rook[0].get(), { File::A, Rank::_8 });
    board->addPieceToBoard(blackPieces.rook[1].get(), { File::H, Rank::_8 });

    board->addPieceToBoard(whitePieces.knight[0].get(), { File::B, Rank::_1 });
    board->addPieceToBoard(whitePieces.knight[1].get(), { File::G, Rank::_1});

    board->addPieceToBoard(blackPieces.knight[0].get(), { File::B, Rank::_8 });
    board->addPieceToBoard(blackPieces.knight[1].get(), { File::G, Rank::_8 });

    board->addPieceToBoard(whitePieces.bishop[0].get(), { File::C, Rank::_1 });
    board->addPieceToBoard(whitePieces.bishop[1].get(), { File::F, Rank::_1});

    board->addPieceToBoard(blackPieces.bishop[0].get(), { File::C, Rank::_8 });
    board->addPieceToBoard(blackPieces.bishop[1].get(), { File::F, Rank::_8 });

    board->addPieceToBoard(whitePieces.queen.get(), { File::D, Rank::_1 });
    board->addPieceToBoard(blackPieces.queen.get(), { File::D, Rank::_8 });

    board->addPieceToBoard(whitePieces.king.get(), { File::E, Rank::_1 });
    board->addPieceToBoard(blackPieces.king.get(), { File::E, Rank::_8 });


    for (int i = 0; i < 8; i++)
    {
        board->addPieceToBoard(whitePieces.pawn[i].get(), {(File)i, Rank::_2});
        board->addPieceToBoard(blackPieces.pawn[i].get(), {(File)i, Rank::_7});
    }
}
