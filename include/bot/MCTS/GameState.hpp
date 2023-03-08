//
// Created by loicp on 27/02/2023.
//

#ifndef NOUVEAU_DOSSIER_GAMESTATE_HPP
#define NOUVEAU_DOSSIER_GAMESTATE_HPP


#include <vector>
#include "game/Board.hpp"

class GameState {
private:
    Board board;
    Color playerColor;
    Color turnColor;

    GameState(Board board, Color color, Color turnColor);

public:
    GameState();
    explicit GameState(Board board, Color color);


    bool isTerminal() const;
    Color getWinner() const;
    std::vector<int> getLegalMoves() const;
    GameState makeMove(int move) const;

    Color getPlayerColor() const;
};


#endif //NOUVEAU_DOSSIER_GAMESTATE_HPP
