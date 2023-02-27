#pragma once
#include "../game/Board.hpp"

class Player 
{
public:
	Color color;

	explicit Player(Color color);
	virtual void play(Board * board) = 0;
};