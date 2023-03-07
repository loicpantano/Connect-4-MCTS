//
// Created by loicp on 27/02/2023.
//

#include "bot/MCTS/GameState.hpp"

GameState::GameState(Board board, Color color): board(board), playerColor(color), turnColor(color) {}

GameState::GameState(Board board, Color color, Color turnColor): board(board), playerColor(color), turnColor(turnColor) {}

GameState::GameState() {

}

bool GameState::isTerminal() {
    return board.isTerminal();
}

Color GameState::getWinner() {
    int nbred = 0;
    int nbyellow = 0;
    for(int i = 0; i < 7; i++) {
        for (int j = 0; j < 6; j++) {
            if (board.board.at(i).at(j) == Color::RED) {
                nbred++;
            }
            if (board.board.at(i).at(j) == Color::YELLOW) {
                nbyellow++;
            }
        }
    }
    if(nbred > nbyellow){
        return Color::RED;
    } else {
        return Color::YELLOW;
    }
}

std::vector<int> GameState::getLegalMoves() {
    std::vector<int> legal_moves;
    if(this->board.checkWin() || this->board.isFull()) return legal_moves;
    for(int i = 0; i < 7; i++) {
        if(board.board.at(i).at(Board::height-1) == NO){
            legal_moves.push_back(i);
        }
    }
    return legal_moves;
}

GameState GameState::makeMove(int move) {
    Board new_board = board;
    new_board.placeJeton(move, turnColor);
    return GameState(new_board, playerColor, turnColor == Color::RED ? Color::YELLOW : Color::RED);
}
