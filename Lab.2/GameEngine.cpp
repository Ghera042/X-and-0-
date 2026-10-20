#include "GameEngine.hpp"

GameEngine::GameEngine() { reset(); }

void GameEngine::reset() {
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            board[r][c] = ' ';
    current = 'X';
    winner = ' ';
    moves = 0;
}

bool GameEngine::isFinished() const { return winner != ' ' || moves == 9; }

bool GameEngine::makeMove(int row, int col) {
    if (isFinished()) return false;
    if (row < 0 || row > 2 || col < 0 || col > 2) return false;
    if (board[row][col] != ' ') return false;

    board[row][col] = current;
    moves++;

    if (isWinning(current))
        winner = current;
    else
        current = (current == 'X') ? '0' : 'X';
    return true;
}

bool GameEngine::isWinning(char p) const {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p) return true;
        if (board[0][i] == p && board[1][i] == p && board[2][i] == p) return true;
    }
    if (board[0][0] == p && board[1][1] == p && board[2][2] == p) return true;
    if (board[0][2] == p && board[1][1] == p && board[2][0] == p) return true;
    return false;
}
