#include "Game.h"
#include "Application.h"

Game* getGame()
{
    return MChessApplication::getApp().getGame();
}

//==============================================================================
Game::Game(Board* mBoard)
{
    board.reset(mBoard);
    startGame();
}

Game::~Game()
{
    board.release();
}

void Game::startGame()
{
    board->startGame();
}

void Game::nextPlayer()
{
    board->nextPlayer();
}