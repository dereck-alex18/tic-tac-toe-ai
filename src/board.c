#include<stdio.h>
#include "board.h"
#include "screen.h"
#define GRID_SIZE 3


char board[3][3];

void printBoard() {
  int row, col;
    screenInit(1);
    
    for (row = 0; row < GRID_SIZE; row++) {
        for (col = 0; col < GRID_SIZE; col++) {
            screenGotoxy(30 + col * 4, 3 + row * 2);  
            printf("%c", board[row][col]);
            if (col < GRID_SIZE - 1) {
                printf(" | ");
                
            }
        }
        
        if (row < GRID_SIZE - 1) {
            screenGotoxy(27, 4 + row * 2); 
            printf("---------------"); 
        }
    }
    
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

