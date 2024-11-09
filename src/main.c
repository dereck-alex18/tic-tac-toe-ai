#include <stdio.h>
#include <stdlib.h>
#include "board.h"
#include "menus.h"
#include "machine_interaction.h"
#include "player.h"
#include "game.h"
#include "ai.h"
#include <unistd.h>
#include "screen.h"
#include "timer.h"
#include "keyboard.h"
#include <string.h>

void handleEnterToContinue()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  getchar();
}

int main(void)
{
  int player = 1;
  int winner = 0;
  char playAgain = 'y';
  int playMode = 0;
  int sameMode = 0;
  Player *player1 = malloc(sizeof(Player));
  Player *player2 = malloc(sizeof(Player));
  timerInit(1000);
  // keyboardInit();
    if(timerTimeOver() == 1){
      printf("TIME OUT!!!\n");
    }
  while (playAgain == 'y' || playAgain == 'Y' || sameMode == 0)
  {
  
    if (sameMode == 0)
    {
      initialMenu(&playMode);
      if(playMode == 0) break;
      if (playMode == 1)
      {

        setPlayerName(player1, 1);
        setPlayerName(player2, 2);
        system("clear");
        printf("You chose Human vs Human. \033[1m%s\033[0m will be \"X\" while \033[1m%s\033[0m will be \"O\"\n", player1->name, player2->name);
        printf("Have fun! :)\n");
        printf("Press ENTER to continue...\n");
        handleEnterToContinue();
      }
      else
      {
        system("clear");
        setPlayerName(player1, 1);
        strcpy(player2->name, "X-Oblivion");
        player2->score = 0;
        printf("You chose Human vs AI. \033[1;32m%s\033[0m mark will be \"X\" while the \033[1;32m%s\033[0m (the AI) will be \"O\"\n", player1->name, player2->name);
        printf("Have fun! :)\n");
        printf("Press ENTER to continue...\n");
        handleEnterToContinue();
        aiLevelSelection();
      }
    }
    resetGame(&player);
    while (checkEmptySpaces())
    {
      printBoard();
      printScore(player1, player2);
      if (playMode == 1 || (playMode == 2 && player == 1))
      {
        playerMove(&player, (player == 1 ? player1->name : player2->name));
      }
      else if (playMode == 2 && player == 2)
      {
        screenGotoxy(9, 9);
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
      printScore(player1, player2);
      if (player == 2 && playMode == 2)
      {
        
        screenGotoxy(9, 9);
        printf("%s wins!\n", player2->name);
        taunt(2);
        setPlayerScore(player2);
      }
      else
      {
        screenGotoxy(9, 11);
        setPlayerScore((player == 1 ? player1 : player2));
        printf("Congratulations player %d, you are the winner!\n", player);
        if (playMode == 2)
        {
          screenGotoxy(9, 9);
          taunt(1);
        }
      }
    }
    else
    {
      printScore(player1, player2);
      setPlayerScore(player1);
      setPlayerScore(player2);
      screenGotoxy(9, 11);
      printf("It's a draw!");
      if(playMode == 2){
        taunt(0);
      }
      
    }
   
    printScore(player1, player2);
    screenGotoxy(9, 12);
    printf("Would you like to play again? (y/n)\n");

    printf("\n");
    screenGotoxy(45, 12);
    scanf("%s", &playAgain);
    
    if(playAgain == 'y'){
      sameMode = 1;
    } else{
      sameMode = 0;
    }
    system("clear");
  }
  
  screenDestroy();
  timerDestroy();
  free(player1);
  free(player2);
  printf("Come back soon! :)\n");
  return 0;
}
