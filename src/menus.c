#include <stdio.h>
#include "menus.h"
#include "keyboard.h"

int aiLevel = 0;

void initialMenu(int *playMode){
    printf("Welcome to the Tic Tac Toe game! Please, choose a game mode: \n");
    printf("1 - Human vs Human\n");
    printf("2 - Human vs AI\n");
    printf("0 - Sair\n");
    scanf("%d", playMode);
    
    if(*playMode > 2 || *playMode < 0){
        printf("Invalid option! Please select a valid one!\n");
        initialMenu(playMode);
    }
}

void aiLevelSelection(){
    printf("\n\nYou chose Human vs AI. Please select the level of the AI: \n");
    printf("1 - Can I play, daddy? 👶\n");
    printf("2 - Hey, take it easy! 😧\n");
    printf("3 - Let's Rock. 😡\n");
    printf("\033[1;31m4 - I'M DEATH INCARNATE!!!\033[0m 😈\n\n");
    scanf("%d", &aiLevel);

    if(aiLevel < 1 || aiLevel > 4){
        printf("Invalid option! Please select a valid one!\n\n");
        aiLevelSelection();
    }
}