#include "Computer.hpp"

#include <cstdlib>
#include <ctime>
#include <vector>

Computer::Computer() { std::srand(static_cast<unsigned>(std::time(nullptr))); }

Move Computer::chooseMove(const GameEngine& game) const {
    std::vector<Move> cells;
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            if (game.board[r][c] == ' ') cells.push_back({ game.current, r, c });
    return cells[std::rand() % cells.size()];
}