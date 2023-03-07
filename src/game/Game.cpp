#include "../../include/game/Game.hpp"
#include <iostream>
#include "../../include/bot/PlayerFactory.hpp"
#include "bot/Human.hpp"
#include "engine/Engine.hpp"
#include <SFML/Graphics.hpp>


Game::Game(char p1, char p2): board(Board()), status(0), turn(0)
{
	players[0] = PlayerFactory::createPlayer(p1, RED);
	players[1] = PlayerFactory::createPlayer(p2, YELLOW);
}

void Game::start()
{
    Engine engine = Engine(this);
    status = 1;
	board.reset();

    while(status == 1) {
        engine.run();
        engine.linkBoard();
        engine.hover();
        engine.refresh();
        if(board.checkWin())
        {
            engine.linkBoard();
            engine.refresh();
            engine.printWinner(turn%2);
            status = 0;
        }else if(board.isFull())
        {
            engine.linkBoard();
            engine.refresh();
            engine.printWinner(-1);
            status = 0;
        }
    }
    engine.stop();
}



