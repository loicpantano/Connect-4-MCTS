//
// Created by loicp on 27/02/2023.
//

#include "bot/Bot.hpp"
#include "bot/MCTS/MCTS.hpp"

void Bot::play(Board * board) {
    MCTS mcts(*board, this->color);
    mcts.run();
    int move = mcts.getMove();
    board->placeJeton(move, this->color);
}

Bot::Bot(Color color) : Player(color) {

}
