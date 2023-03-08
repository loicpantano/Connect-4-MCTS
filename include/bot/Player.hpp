#pragma once
#include "../game/Board.hpp"

class Player 
{
private:
	Color color;
public:
	explicit Player(Color color);
	virtual void play(Board * board) = 0;

    Color getColor() const;
};