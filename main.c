#include "game.h"
#include "board.h"

int main() {
    initBoard();
    while (!isGameOver()) {
        displayBoard();
        processInput();
    }
    return 0;
}
