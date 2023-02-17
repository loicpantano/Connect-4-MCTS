#include "../../include/game/Game.hpp"
#include <iostream>
#include "../../include/bot/PlayerFactory.hpp"


Game::Game(char p1, char p2): board(Board()), status(0)
{
	players[0] = PlayerFactory::createPlayer(p1, RED);
	players[1] = PlayerFactory::createPlayer(p2, YELLOW);
}

void Game::start()
{
	status = 1;
	board.reset();
	while(status == 1)
	{
		std::cout << "Red" << std::endl;
		playTurn(0);
		std::cout << board << std::endl;
		if(status == 1)
		{
			std::cout << "Yellow" << std::endl;
		playTurn(1);
		std::cout << board << std::endl;
		}
		
	}
	std::cout << "Red: " << players[0]->score << std::endl;
	std::cout << "Yellow: " << players[1]->score << std::endl;
}

void Game::playTurn(int i)
{
	players[i]->play(&board);
	if(board.checkWin())
	{
		players[i]->score++;
		if(i == 0)
			std::cout << "Red wins!" << std::endl;
		else
			std::cout << "Yellow wins!" << std::endl;
		status = 0;
		return;
	}

}

