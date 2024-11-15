#include "board.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
#define WIN_TILE 2048
int board[SIZE][SIZE];

void initBoard() {
    srand(time(0));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = 0;
        }
    }
    addTile();
    addTile();
}

void displayBoard() {
    system("cls");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%4d", board[i][j]);
        }
        printf("\n");
    }
}

void addTile() {
    int empty[SIZE * SIZE][2];
    int emptyCount = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                empty[emptyCount][0] = i;
                empty[emptyCount][1] = j;
                emptyCount++;
            }
        }
    }
    if (emptyCount > 0) {
        int r = rand() % emptyCount;
        board[empty[r][0]][empty[r][1]] = (rand() % 2 + 1) * 2;
    }
}

void moveUp() {
    for (int j = 0; j < SIZE; j++) {
        for (int i = 1; i < SIZE; i++) {
            if (board[i][j] != 0) {
                int k = i;
                while (k > 0 && board[k-1][j] == 0) {
                    board[k-1][j] = board[k][j];
                    board[k][j] = 0;
                    k--;
                }
                if (k > 0 && board[k-1][j] == board[k][j]) {
                    board[k-1][j] *= 2;
                    board[k][j] = 0;
                }
            }
        }
    }
}

void moveDown() {
    for (int j = 0; j < SIZE; j++) {
        for (int i = SIZE - 2; i >= 0; i--) {
            if (board[i][j] != 0) {
                int k = i;
                while (k < SIZE - 1 && board[k+1][j] == 0) {
                    board[k+1][j] = board[k][j];
                    board[k][j] = 0;
                    k++;
                }
                if (k < SIZE - 1 && board[k+1][j] == board[k][j]) {
                    board[k+1][j] *= 2;
                    board[k][j] = 0;
                }
            }
        }
    }
}

void moveLeft() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 1; j < SIZE; j++) {
            if (board[i][j] != 0) {
                int k = j;
                while (k > 0 && board[i][k-1] == 0) {
                    board[i][k-1] = board[i][k];
                    board[i][k] = 0;
                    k--;
                }
                if (k > 0 && board[i][k-1] == board[i][k]) {
                    board[i][k-1] *= 2;
                    board[i][k] = 0;
                }
            }
        }
    }
}

void moveRight() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = SIZE - 2; j >= 0; j--) {
            if (board[i][j] != 0) {
                int k = j;
                while (k < SIZE - 1 && board[i][k+1] == 0) {
                    board[i][k+1] = board[i][k];
                    board[i][k] = 0;
                    k++;
                }
                if (k < SIZE - 1 && board[i][k+1] == board[i][k]) {
                    board[i][k+1] *= 2;
                    board[i][k] = 0;
                }
            }
        }
    }
}

int checkWin() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == WIN_TILE) {
                return 1;
            }
        }
    }
    return 0;
}

int checkFull() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
            // Check if there's a possible move left
            if ((i > 0 && board[i][j] == board[i-1][j]) || 
                (i < SIZE - 1 && board[i][j] == board[i+1][j]) ||
                (j > 0 && board[i][j] == board[i][j-1]) ||
                (j < SIZE - 1 && board[i][j] == board[i][j+1])) {
                return 0;
            }
        }
    }
    return 1;
}
