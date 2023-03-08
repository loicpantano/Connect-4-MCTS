#include "../../include/bot/Player.hpp"

Player::Player(Color color) : color(color) {}

Color Player::getColor() const {
    return color;
}
