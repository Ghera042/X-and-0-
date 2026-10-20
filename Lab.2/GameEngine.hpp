#pragma once

class GameEngine {
public:
    char board[3][3];
    char current;
    char winner;
    int moves;

    GameEngine();

    void reset();
    bool isFinished() const;
    bool makeMove(int row, int col);

private:
    bool isWinning(char p) const;
};
