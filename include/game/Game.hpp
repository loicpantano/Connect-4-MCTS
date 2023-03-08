#pragma once
#include <array>
#include <memory>

#include "Board.hpp"
#include "../bot/Player.hpp"

class Game
{
public:
    Board board;
	std::array<std::unique_ptr<Player>, 2> players;
	int status;
    int turn;

	Game(char p1, char p2);

	void start();

};

