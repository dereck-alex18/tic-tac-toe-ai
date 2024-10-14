#include <stdio.h>
#include "board.h"
#include "player.h"
#include "game.h"

int main(void) {
  int player = 1;
  int winner = 0;
  char playAgain = 'y';

  while (playAgain == 'y' || playAgain == 'Y') {
    resetGame(&player);
    while (checkEmptySpaces()) {
      printBoard();
      playerMove(&player);
      winner = checkWinner();

      if (winner == 1) {
        break;
      }
      swapPlayers(&player);
    }
    printBoard();

    if (winner) {
      printf("Congratulations player %d, you are the winner!\n", player);
    } else {
      printf("The game was a Tie! ");
    }

    printf("Would you like to play again? (y/n)\n");
    scanf("%s", &playAgain);
  }
  printf("Come back soon! :)\n");
  return 0;
}

void resetGame(int *player);
void printBoard();
int checkEmptySpaces();
void swapPlayers(int *player);
void playerMove(int *player);
int checkWinner();
