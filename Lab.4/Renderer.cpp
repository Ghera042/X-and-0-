#include "Renderer.hpp"

#include <ostream>

void Renderer::draw(const GameEngine& game) const {
    out_ << "\n     1   2   3\n";
    for (int r = 0; r < 3; r++) {
        out_ << "   +---+---+---+\n";
        out_ << " " << r + 1 << " |";
        for (int c = 0; c < 3; c++)
            out_ << " " << game.board[r][c] << " |";
        out_ << "\n";
    }
    out_ << "   +---+---+---+\n\n";

    if (game.winner != ' ')
        out_ << "A castigat " << game.winner << "\n";
    else if (game.isFinished())
        out_ << "Egalitate\n";
    else
        out_ << "Merge " << game.current << "\n";

    if (game.isFinished()) {
        for (char player : {'X', '0'}) {
            out_ << "\n";
        }
    }
}

void Renderer::drawMenu() const {
    out_ << " \n X si 0 \n"
        << "1 - joc contra altui jucator\n"
        << "2 - joc contra calculatorului\n"
        << "q - iesire\n";
}

void Renderer::drawHelp() const {
    out_ << "r = restart, q = iesire\n";
}



void Renderer::drawInvalidChoice() const { out_ << "\nAlege din variantele propuse\n"; }

void Renderer::drawInvalidMove() const { out_ << "Mutare gresita\n"; }

void Renderer::drawUnknownCommand() const {
    ou