//
// Created by loicp on 27/02/2023.
//

#include "bot/Bot.hpp"
#include "bot/MCTS/MCTS.hpp"

void Bot::play(Board *board) {
    MCTS mcts(*board, this->getColor());
    mcts.run();
    int move = mcts.getMove();
    board->placeJeton(move, this->getColor());
}

Bot::Bot(Color color) : Player(color) {

}
