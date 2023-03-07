//
// Created by loicp on 27/02/2023.
//

#ifndef NOUVEAU_DOSSIER_GAMESTATE_HPP
#define NOUVEAU_DOSSIER_GAMESTATE_HPP


#include <vector>
#include "game/Board.hpp"

class GameState {
public:
    Board board;
    Color playerColor;
    Color turnColor;
    GameState();
    explicit GameState(Board board, Color color);
    GameState(Board board, Color color, Color turnColor);
    bool isTerminal();
    Color getWinner();
    std::vector<int> getLegalMoves();
    GameState makeMove(int move);
};


#endif //NOUVEAU_DOSSIER_GAMESTATE_HPP
