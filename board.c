#include<stdio.h>
#include "board.h"


char board[3][3];

void printBoard() {
  printf(" %c | %c | %c", board[0][0], board[0][1], board[0][2]);
  printf("\n---|---|---\n");
  printf(" %c | %c | %c", board[1][0], board[1][1], board[1][2]);
  printf("\n---|---|---\n");
  printf(" %c | %c | %c", board[2][0], board[2][1], board[2][2]);
  printf("\n---|---|---\n");
}

int checkEmptySpaces() {

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ') {
        return 1;
      }
    }
  }

  return 0;
}

void resetGame(int *player) {
  *player = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = ' ';
    }
  }
}

