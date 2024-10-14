#include <stdio.h>
#include "board.h"
#include "player.h"
#include "ai.h"

void aiMove(int *player){
    int mark = 1;
    for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
            if(board[i][j] == ' '){
                board[i][j] = PLAYER_2;
                mark = 0;
                break;
            }
            
        }
        if(!mark) break;
    }
}