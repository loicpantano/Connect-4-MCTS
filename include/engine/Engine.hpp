//
// Created by loicp on 27/02/2023.
//
#include "game/Board.hpp"
#include "game/Game.hpp"
#include <SFML/Graphics.hpp>

#ifndef NOUVEAU_DOSSIER_ENGINE_HPP
#define NOUVEAU_DOSSIER_ENGINE_HPP


class Engine {
private:
    sf::RenderWindow window;
    sf::CircleShape boardg[Board::width][Board::height];
    std::unique_ptr<Game> game;
public:
    explicit Engine(Game *game);

    void run();

    void refresh();

    void linkBoard();

    void hover();

    void stop();

    void printWinner(int i);
};


#endif //NOUVEAU_DOSSIER_ENGINE_HPP
