#pragma once

#include <JuceHeader.h>
#include "Board/Board.h"

//==============================================================================
/*
	This component lives inside our window, and this is where you should put all
	your controls and content.
*/
class Game
{
public:
	//==============================================================================
	Game(std::shared_ptr<Board> mBoard);
	~Game();

	void startGame();

	void nextPlayer();
	Colour getCurrentPlayer() const;

	void makeMove(PieceBase* piece, Square* square);

	int getNumValidMoves(const Colour& player) const;

	float getEvaluationValue() const;

	std::shared_ptr<Board> const getBoard() const;

private:
	//==============================================================================
	// Your private member variables go here...
	std::shared_ptr<Board> board;

	juce::OwnedArray<PieceBase> whitePieces, blackPieces;

	void initStandardGame();

	Colour currentPlayer;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Game)
};

/**
* @brief     Returns a Pointer to our MChessApplication game
*/
Game* getGame();