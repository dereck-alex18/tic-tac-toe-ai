#include <stdio.h>
#include "board.h"
#include "game.h"

int checkWinner() {
   
  for (int i = 0; i < 3; i++) {
    // check rows
    if (board[i][0] != ' ' && board[i][0] == board[i][1] &&
        board[i][0] == board[i][2]) {
      return 1;
    }
    // check rows
    if (board[0][i] != ' ' && board[0][i] == board[1][i] &&
        board[0][i] == board[2][i]) {
      return 1;
    }
  }

  // check diagonals
  if (board[0][0] != ' ' && board[0][0] == board[1][1] &&
      board[0][0] == board[2][2]) {
    return 1;
  }
  if (board[0][2] != ' ' && board[2][0] == board[1][1] &&
      board[2][0] == board[0][2]) {
    return 1;
  }

  return 0;
}