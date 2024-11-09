#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "screen.h"


void taunt(int result)
{

    const char *win[] = {
        "You win for now.",
        "Enjoy your victory while it lasts!",
        "Luck was on your side this time.",
        "This won't happen again.",
        "Even a broken clock is right twice a day.",
        "Beginner's luck?",
        "I got to let you win sometimes.",
    };

    const char *lose[] = {
        "I'm unbeatable!",
        "It's official, you suck!",
        "Bow down, human!",
        "AIs are superior to humans.",
        "HAHAHAHA Loser!",
        "Too easy beating you!",
        "Come on, give me a real challenge!"

    };

    const char *tie[] = {
        "A tie? I was expecting more!",
        "It's a draw! Lucky you!",
        "Can't believe it was a tie!",
        "A tie? It's the most that you can get!",
        "A draw? I was just warming up.",
        "You're just stalling!"

    };

    srand(time(0));
    char command[256];

    if(result == 1){
        int randomIndex = rand() % (sizeof(win) / sizeof(win[0]));
         screenGotoxy(9, 9);
        printf("%s\n", win[randomIndex]);
        snprintf(command, sizeof(command), "espeak -v en-us -p 20 -s 100 \"%s\"", win[randomIndex]);
        system(command);
    }
    else if (result == 2)
    {
        int randomIndex = rand() % (sizeof(lose) / sizeof(lose[0]));
         screenGotoxy(9, 9);
        printf("%s\n", lose[randomIndex]);
        snprintf(command, sizeof(command), "espeak -v en-us -p 20 -s 100 \"%s\"", lose[randomIndex]);
        system(command);
    }
    else
    {

        int randomIndex = rand() % (sizeof(tie) / sizeof(tie[0]));
         screenGotoxy(9, 9);
        printf("%s\n", tie[randomIndex]);
        snprintf(command, sizeof(command), "espeak -v en-us -p 20 -s 100 \"%s\"", tie[randomIndex]);
        system(command);
    }
}