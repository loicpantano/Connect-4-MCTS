#include <iostream>
#include <ostream>

#include "../include/game/Board.hpp"
#include "../include/game/Game.hpp"

int main() {
    /*
	char p1, p2;
	std::cout << "Enter the type of player 1 (h for human, b for bot): " << std::endl;
	std::cin >> p1;
	std::cout << "Enter the type of player 2 (h for human, b for bot): " << std::endl;
	std::cin >> p2;
*/
    Game game = Game('h', 'b');
    game.start();
}
