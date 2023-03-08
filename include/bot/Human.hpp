#pragma once

#include "Player.hpp"

class Human :
        public Player {
public:
    Human(Color color);

    void play(Board *board) override;
};

