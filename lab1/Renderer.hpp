#pragma once

#include <iostream>

#include "GameEngine.hpp"


class Renderer {
public:
    void draw(const GameEngine& game) const {
        std::cout << "\n     1   2   3\n";
        for (int r = 0; r < 3; r++) {
            std::cout << "   +---+---+---+\n";
            std::cout << " " << r + 1 << " |";
            for (int c = 0; c < 3; c++)
                std::cout << " " << game.board[r][c] << " |";
            std::cout << "\n";
        }
        std::cout << "   +---+---+---+\n\n";

        if (game.winner != ' ')
            std::cout << "A castigat " << game.winner << "!\n";
        else if (game.isFinished())
            std::cout << "Egalitate\n";
        else
            std::cout << "Merge" << game.current << "\n";
    }

    void message(const char* text) const { std::cout << text << "\n"; }
};
