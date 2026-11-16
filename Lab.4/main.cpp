#include "GameEngine.hpp"
#include "Listener.hpp"
#include "Renderer.hpp"

int main() {
    GameEngine game;
    Renderer renderer;
    Listener listener;

    renderer.message("X si 0");
    renderer.message("r = restart, q = iesire");

    while (true) {
        renderer.draw(game);

        int row = 0, col = 0;
        char cmd = listener.listen(row, col);

        if (cmd == 'q') break;
        if (cmd == 'r')
            game.reset();
        else if (cmd == 'm') {
            if (!game.makeMove(row, col))
                renderer.message("Meiscare gresita");
        } else
            renderer.message("Comanda necunoscuta");
    }

   
    return 0;
}
