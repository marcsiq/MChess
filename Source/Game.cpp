#include "Game.h"
#include "Application.h"
#include "Pieces/Pieces.h"

Game* getGame()
{
	return MChessApplication::getApp().getGame();
}

//==============================================================================
Game::Game(std::shared_ptr<Board> mBoard)
{
	board = mBoard;

	startGame();
}

Game::~Game()
{
	board.reset();
}

void Game::startGame()
{
	board->initBoard();
	initStandardGame();
	currentPlayer = Colour::WHITE;

	DBG("VALID MOVES FOR " << colourToString[currentPlayer] << " -> " << juce::String(getNumValidMoves(currentPlayer)));
	DBG("EVALUATION: " << getEvaluationValue());
}

void Game::nextPlayer()
{
	currentPlayer = (currentPlayer == Colour::WHITE ? Colour::BLACK : Colour::WHITE);
	DBG("VALID MOVES FOR " << colourToString[currentPlayer] << " -> " << juce::String(getNumValidMoves(currentPlayer)));
	DBG("EVALUATION: " << getEvaluationValue());
}

Colour Game::getCurrentPlayer() const
{
	return currentPlayer;
}

void Game::makeMove(PieceBase* piece, Square* square)
{
	board->movePiece(piece, square);
	nextPlayer();
}

std::shared_ptr<Board> const Game::getBoard() const
{
	return board;
}

int Game::getNumValidMoves(const Colour& player) const
{
	juce::Array<Location> moves;

	if (player == Colour::WHITE)
	{
		for (auto& p : whitePieces)
		{
			moves.addArray(p->getValidMoves(*board.get()));
		}
	}
	else if (player == Colour::BLACK)
	{
		for (auto& p : blackPieces)
		{
			moves.addArray(p->getValidMoves(*board.get()));
		}
	}

	return (int)moves.size();
}

void Game::initStandardGame()
{
	whitePieces.add(new Rook{ Colour::WHITE });
	board->addPieceToBoard(whitePieces.getLast(), { File::A, Rank::_1 });
	whitePieces.add(new Rook{ Colour::WHITE });
	board->addPieceToBoard(whitePieces.getLast(), { File::H, Rank::_1 });

	blackPieces.add(new Rook{ Colour::BLACK });
	board->addPieceToBoard(blackPieces.getLast(), { File::A, Rank::_8 });
	blackPieces.add(new Rook{ Colour::BLACK });
	board->addPieceToBoard(blackPieces.getLast(), { File::H, Rank::_8 });

	whitePieces.add(new Knight{ Colour::WHITE });
	board->addPieceToBoard(whitePieces.getLast(), { File::B, Rank::_1 });
	whitePieces.add(new Knight{ Colour::WHITE });
	board->addPieceToBoard(whitePieces.getLast(), { File::G, Rank::_1 });

	blackPieces.add(new Knight{ Colour::BLACK });
	board->addPieceToBoard(blackPieces.getLast(), { File::B, Rank::_8 });
	blackPieces.add(new Knight{ Colour::BLACK });
	board->addPieceToBoard(blackPieces.getLast(), { File::G, Rank::_8 });

	whitePieces.add(new Bishop{ Colour::WHITE });
	board->addPieceToBoard(whitePieces.getLast(), { File::C, Rank::_1 });
	whitePieces.add(new Bishop{ Colour::WHITE });
	board->addPieceToBoard(whitePieces.getLast(), { File::F, Rank::_1 });

	blackPieces.add(new Bishop{ Colour::BLACK });
	board->addPieceToBoard(blackPieces.getLast(), { File::C, Rank::_8 });
	blackPieces.add(new Bishop{ Colour::BLACK });
	board->addPieceToBoard(blackPieces.getLast(), { File::F, Rank::_8 });

	whitePieces.add(new Queen{ Colour::WHITE });
	board->addPieceToBoard(whitePieces.getLast(), { File::D, Rank::_1 });

	blackPieces.add(new Queen{ Colour::BLACK });
	board->addPieceToBoard(blackPieces.getLast(), { File::D, Rank::_8 });

	whitePieces.add(new King{ Colour::WHITE });
	board->addPieceToBoard(whitePieces.getLast(), { File::E, Rank::_1 });

	blackPieces.add(new King{ Colour::BLACK });
	board->addPieceToBoard(blackPieces.getLast(), { File::E, Rank::_8 });

	for (int i = 0; i < 8; i++)
	{
		whitePieces.add(new Pawn{ Colour::WHITE });
		board->addPieceToBoard(whitePieces.getLast(), { (File)i, Rank::_2 });
		blackPieces.add(new Pawn{ Colour::BLACK });
		board->addPieceToBoard(blackPieces.getLast(), { (File)i, Rank::_7 });
	}
}

float Game::getEvaluationValue() const
{
	float value = 0.0f;

	for (auto& p : whitePieces)
	{
		if (!p->hasBeenCaptured())
		{
			value += p->getPieceValue();
		}
	}

	for (auto& p : blackPieces)
	{
		if (!p->hasBeenCaptured())
		{
			value -= p->getPieceValue();
		}
	}

	return value;
}