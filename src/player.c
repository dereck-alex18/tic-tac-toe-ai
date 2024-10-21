#include <stdio.h>
#include "board.h"
#include "player.h"

void playerMove(int *player) {
  int row, col;

  printf("Player %d turn\n", *player);
  printf("Enter the row and column you want to play\n: ");
  scanf("%d %d", &row, &col);
  row--;
  col--;
  while (board[row][col] != ' ') {
    printf("That space is already taken or it's invalid, please choose another "
           "space\n");
    printf("Enter the row and column you want to play\n: ");
    scanf("%d %d", &row, &col);
    row--;
    col--;
  }

  if (*player == 1) {
    board[row][col] = PLAYER_1;
  } else {
    board[row][col] = PLAYER_2;
  }
}

void swapPlayers(int *player) { *player = (*player == 1) ? 2 : 1; }