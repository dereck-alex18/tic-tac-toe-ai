#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "board.h"
#include "player.h"
#include "menus.h"
#include "game.h"
#include "ai.h"

int minMaxWithDepth(int isMaximizing, int depth)
{
    int score = 0;

    if (depth == 0)
        return 0;

    score = checkWinner();
    if (score != 0)
        return score;

    if (!checkEmptySpaces())
        return 0; // Tie

    if (isMaximizing)
    {

        int bestScore = 1000;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = PLAYER_2;
                    int score = minMaxWithDepth(0, depth - 1);
                    board[i][j] = ' ';
                    bestScore = (score < bestScore) ? score : bestScore;
                }
            }
        }

        return bestScore;
    }
    else
    {
        int bestScore = -1000, score = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == ' ')
                {
                    board[i][j] = PLAYER_1;
                    score = minMaxWithDepth(1, depth - 1);
                    board[i][j] = ' ';
                    bestScore = (score > bestScore) ? score : bestScore;
                }
            }
        }

        return bestScore;
    }
}

void aiMove(int *player)
{
    srand(time(0));
    int bestScore = 1000, bestRow = -1, bestCol = -1, depth = aiLevel * 1000, score;

    switch (aiLevel)
    {
    case 1:
        depth = 2;
        break;
    case 2:
        depth = 3;
        break;
    case 3:
        depth = 4;
        break;
    case 4:
        depth = 100000;
        break;

    default:
        break;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                board[i][j] = PLAYER_2;
                score = minMaxWithDepth(0, depth - 1);
                board[i][j] = ' ';

                if (score < bestScore)
                {
                    bestScore = score;
                    bestRow = i;
                    bestCol = j;
                }
            }
        }
    }

    if (depth == 3 && rand() % 10 < 5)
    {
        do
        {
            bestRow = rand() % 3;
            bestCol = rand() % 3;
        } while (board[bestRow][bestCol] != ' ');
    } else if(depth == 4 && rand() % 10 < 2){
        do
        {
            bestRow = rand() % 3;
            bestCol = rand() % 3;
        } while (board[bestRow][bestCol] != ' ');
    }

    board[bestRow][bestCol] = PLAYER_2;

    printf("Ai chooses row: %d and col: %d\n\n", bestRow, bestCol);
}
