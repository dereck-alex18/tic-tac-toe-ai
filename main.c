#include <stdio.h>
#include "board.h"
#include "menus.h"
#include "machine_interaction.h"
#include "player.h"
#include "game.h"
#include "ai.h"
#include <unistd.h>

int main(void)
{
  int player = 1;
  int winner = 0;
  char playAgain = 'y';
  int playMode = 0;

  

  while (playAgain == 'y' || playAgain == 'Y')
  {
    initialMenu(&playMode);
    if (playMode == 1)
    {
      printf("You chose Human vs Human. The player 1 mark will be X while the player 2 will be O\n");
      printf("Have fun! :)\n");
    }
    else
    {
      
      aiLevelSelection();
    }

    resetGame(&player);
    while (checkEmptySpaces())
    {
      printBoard();
      if(playMode == 1 || (playMode == 2 && player == 1)){
        playerMove(&player);
      } else if(playMode == 2 && player == 2){
        printf("AI is thinking...\n");
        sleep(2);
        aiMove(&player);
      }
      
      winner = checkWinner();

      if (winner == 1 || winner == -1)
      {
        break;
      }
      swapPlayers(&player);
    }
    printBoard();

    if (winner)
    {
      if(player == 2 && playMode == 2){
        printf("\nAI wins!\n");
        taunt(2);
      }else{
        printf("Congratulations player %d, you are the winner!\n", player);
        if(playMode == 2){
          taunt(1);
        }
        
      }
      
    }
    else
    {
      printf("The game was a Tie!\n");
      taunt(0);
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
