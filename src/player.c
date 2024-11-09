#include <stdio.h>
#include "board.h"
#include "player.h"
#include "screen.h"

void playerMove(int *player, char *playerName)
{
  int row, col;
  screenGotoxy(9, 9);
  printf("\t\tIt's %s turn\n", playerName);
  printf("\t\tEnter the row and column you want to play: ");
  scanf("%d %d", &row, &col);
  row--;
  col--;
  while (board[row][col] != ' ')
  {
    printf("That space is already taken or it's invalid, please choose another "
           "space\n");
    printf("Enter the row and column you want to play\n: ");
    scanf("%d %d", &row, &col);
    row--;
    col--;
  }

  if (*player == 1)
  {
    board[row][col] = PLAYER_1;
  }
  else
  {
    board[row][col] = PLAYER_2;
  }
}

void setPlayerName(Player *player, int playerNumber)
{
  printf("Enter the player %d name: \n", playerNumber);
  scanf("%s", player->name);
  player->score = 0;
  printf("\n");
}

void setPlayerScore(Player *player)
{

  player->score++;
}

void printScore(Player *player1, Player *player2)
{
  screenGotoxy(50, 5);
  printf("\033[1m%s %d vs \033[1m%s %d\033[0m", player1->name, player1->score, player2->name, player2->score);
}

void swapPlayers(int *player) { *player = (*player == 1) ? 2 : 1; }