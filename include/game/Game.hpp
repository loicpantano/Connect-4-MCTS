#pragma once
#include <array>
#include <memory>

#include "Board.hpp"
#include "../bot/Player.hpp"

class Game
{
private:
	Board board;
	std::array<std::unique_ptr<Player>, 2> players;
	int status;

public:
	Game(char p1, char p2);
	void start();
	void playTurn(int i);

};

