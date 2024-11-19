#include <stdio.h>
#include "board.h"
#include "game.h"
#include "player.h"

int checkWinner() {
   
  for (int i = 0; i < 3; i++) {
    
    if (board[i][0] != ' ' && board[i][0] == board[i][1] &&
        board[i][0] == board[i][2]) {
      return board[i][0] == PLAYER_1 ? 1 : -1;
    }
  
    if (board[0][i] != ' ' && board[0][i] == board[1][i] &&
        board[0][i] == board[2][i]) {
      return board[0][i] == PLAYER_1 ? 1 : -1;
    }
  }


  if (board[0][0] != ' ' && board[0][0] == board[1][1] &&
      board[0][0] == board[2][2]) {
    return board[0][0] == PLAYER_1 ? 1 : -1;
  }
  if (board[0][2] != ' ' && board[2][0] == board[1][1] &&
      board[2][0] == board[0][2]) {
    return board[0][2] == PLAYER_1 ? 1 : -1;
  }

  return 0;
}