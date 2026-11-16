#pragma once

#include <iosfwd>

class GameEngine {
public:
    char board[3][3];
    char current;
    char winner;
    int moves;

    GameEngine();                                                   // constructor implicit
    GameEngine(const char b[3][3], char cur, char win, int m);      // constructor cu parametri
    GameEngine(const GameEngine& other);                            // constructor de copiere
    GameEngine& operator=(const GameEngine& other);                 // operator de atribuire

    bool operator==(const GameEngine& other) const;                // operatori de comparare
    bool operator!=(const GameEngine& other) const;

    void reset();
    bool isFinished() const;
    bool makeMove(int row, int col);

private:
    bool isWinning(char p) const;
};

// operatori de intrare si iesire
std::ostream& operator<<(std::ostream& out, const GameEngine& game);
std::istream& operator>>(std::istream& in, GameEngine& game);
