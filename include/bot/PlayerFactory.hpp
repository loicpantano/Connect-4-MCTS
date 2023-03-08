#pragma once

#include <memory>

#include "Player.hpp"

class PlayerFactory {
public:
    static std::unique_ptr<Player> createPlayer(char type, Color color);
};

