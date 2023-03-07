//
// Created by loicp on 27/02/2023.
//

#ifndef NOUVEAU_DOSSIER_BOT_HPP
#define NOUVEAU_DOSSIER_BOT_HPP


#include "game/Color.hpp"
#include "game/Board.hpp"
#include "Player.hpp"

class Bot:
        public Player{
public:
    void play(Board * board) override;
    explicit Bot(Color color);
};


#endif //NOUVEAU_DOSSIER_BOT_HPP
