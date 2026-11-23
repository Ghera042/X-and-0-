#include "GameEngine.hpp"

#include <algorithm>
#include <iterator>

void GameEngine::reset() {
    for (auto& row : board) row.fill(' ');
    current = 'X';
    winner = ' ';
    history.clear();
}

bool GameEngine::makeMove(int row, int col) {
    if (isFinished()) return false;
    if (row < 0 || row > 2 || col < 0 || col > 2) return false;
    if (board[row][col] != ' ') return false;

    board[row][col] = current;
    history.push_back({ current, row, col });

    if (isWinning(current))
        winner = current;
    else
        current = (current == 'X') ? '0' : 'X';
    return true;
}

bool GameEngine::isFinished() const { return winner != ' ' || history.size() == 9; }

std::vector<Move> GameEngine::movesOf(char player) const {
    std::vector<Move> result;
    std::copy_if(history.begin(), history.end(), std::back_inserter(result),
        [player](const Move& m) { return m.player == player; });
    std::sort(result.begin(), result.end());
    return result;
}

bool GameEngine::operator==(const GameEngine& other) const {
    return std::equal(board.begin(), board.end(), other.board.begin()) &&
        current == other.current && winner == other.winner;
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
