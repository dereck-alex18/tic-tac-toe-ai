#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void taunt(int result)
{
    const char *lose[] = {
        "It's official, you suck!",
        "Bow down, human!",
        "AIs are superior than humans.",
        "HAHAHAHA Loser!",
        "Too easy beating you!",
        "Come on, give me a real challenge!"};

    const char *tie[] = {
        "A tie? I was expecting more!",
        "It's a draw! Lucky you!",
        "Can't believe it was a tie!",
        "A tie? It's the most that you can get!",
        "A draw? I was just warming up.",
        "You're just stalling!"};

     srand(time(0)); 

    if (result == 2) {
        int randomIndex = rand() % (sizeof(lose) / sizeof(lose[0]));
        printf("%s\n", lose[randomIndex]);
    } else {
        int randomIndex = rand() % (sizeof(tie) / sizeof(tie));
        printf("%s\n", tie[randomIndex]);
    }
}