#include "game.h"
#include "board.h"
#include <stdio.h>
#include <conio.h> // Untuk _getch()

void processInput() {
    char input = _getch(); // Mengambil input tanpa menunggu enter
    switch (input) {
        case 'w': moveUp(); break;
        case 's': moveDown(); break;
        case 'a': moveLeft(); break; 
        case 'd': moveRight(); break;
    }
    addTile();
}

int isGameOver() {
    if (checkWin()) {
        printf("Selamat! Anda mencapai 2048!\n");
        return 1;
    }
    if (checkFull()) {
        printf("Permainan selesai. Tidak ada gerakan yang tersisa.\n");
        return 1;
    }
    return 0;
}
