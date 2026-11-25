#pragma once

#include <array>
#include <vector>

struct Move {
    char player;
    int row;
    int col;
};

inline bool operator<(const Move& a, const Move& b) {
    return a.row * 3 + a.col < b.row * 3 + b.col;
}

class GameEngine {
public:
    std::array<std::array<char, 3>, 3> board;
    char current;
    char winner;
    std::vector<Move> history;

    GameEngine() { reset(); }

    void reset();
    bool makeMove(int row, int col);
    bool isFinished() const;
    std::vector<Move> movesOf(char player) const;

    bool operator==(const GameEngine& other) const;
    bool operator!=(const GameEngine& other) const { return !(*this == other); }

private:
    bool isWinning(char player) const;
};