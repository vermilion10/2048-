#ifndef BOARD_H
#define BOARD_H

void initBoard(void);
void displayBoard(void);
void addTile(void);
void moveUp(void);
void moveDown(void);
void moveLeft(void);
void moveRight(void);
int checkWin(void);
int checkFull(void);

#endif
