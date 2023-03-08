//
// Created by loicp on 27/02/2023.
//

#include "bot/MCTS/GameState.hpp"


//Constructors

GameState::GameState(Board board, Color color) : board(board), playerColor(color), turnColor(color) {}

GameState::GameState() {}

GameState::GameState(Board board, Color color, Color turnColor) : board(board), playerColor(color),
                                                                  turnColor(turnColor) {}

//Functions

bool GameState::isTerminal() const {
    return board.isTerminal();
}

Color GameState::getWinner() const {
    return board.getWinner();
}

std::vector<int> GameState::getLegalMoves() const {
    return board.getLegalMoves();
}

GameState GameState::makeMove(int move) const {
    Board new_board = board;
    new_board.placeJeton(move, turnColor);
    return GameState(new_board, playerColor, turnColor == Color::RED ? Color::YELLOW : Color::RED);
}

//Getters

Color GameState::getPlayerColor() const {
    return playerColor;
}
