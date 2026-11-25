#include <iostream>
#include <memory>

#include "BaseRenderer.hpp"
#include "Computer.hpp"
#include "GameEngine.hpp"
#include "Listener.hpp"
#include "Renderer.hpp"
#include "Storage.hpp"

int main() {
    GameEngine game;
    Computer computer;
    Storage storage("tictactoe.db");
    Listener listener(std::cin);
    std::unique_ptr<BaseRenderer> renderer = std::make_unique<Renderer>(std::cout);

    char mode = '?';
    while (mode == '?') {
        renderer->drawMenu();
        mode = listener.listenMode();
        if (mode == '?') renderer->drawInvalidChoice();
    }
    if (mode == 'q') return 0;

    renderer->drawHelp();

    while (true) {
        renderer->draw(game);
       

        int row = 0, col = 0;
        char cmd = listener.listen(row, col);

        if (cmd == 'q') break;
        if (cmd == 'r')
            game.reset();
        else if (cmd == 'm') {
            if (!game.makeMove(row, col)) {
                renderer->drawInvalidMove();
            }
            else {
                if (mode == '2' && !game.isFinished()) {
                    Move move = computer.chooseMove(game);
                    game.makeMove(move.row, move.col);
                }
                if (game.isFinished())
                    storage.saveResult(mode - '0', game.winner);
            }
        }
        else
            renderer->drawUnknownCommand();
    }
    return 0;
}