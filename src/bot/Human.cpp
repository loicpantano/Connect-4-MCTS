#include "../../include/bot/Human.hpp"
#include <iostream>

Human::Human(Color color) : Player(color) {}


void Human::play(Board * board)
{
	int column;
	do {
			std::cout << "Enter a column number: " << std::endl; 
			std::cin >> column;
		} while (!board->placeJeton(column, color));
}
