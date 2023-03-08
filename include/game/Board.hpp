#pragma once

#include <array>
#include <string>
#include <vector>
#include "Color.hpp"

class Board {
public:
    static constexpr int width = 7;
    static constexpr int height = 6;
    std::array<std::array<Color, height>, width> board;

    Board();

    bool placeJeton(int column, Color color);

    void reset();

    bool isFull() const;

    bool checkWin() const;

    bool isTerminal() const;

    Color getWinner() const;

    std::vector<int> getLegalMoves() const;

    friend std::ostream &operator<<(std::ostream &os, const Board &obj);
};

