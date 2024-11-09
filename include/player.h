#ifndef PLAYER_H
#define PLAYER_H
#define PLAYER_1 'X'
#define PLAYER_2 'O'

struct {
    char name[50];
    int score;
} typedef Player;

void playerMove(int *player, char *playerName);
void swapPlayers(int *player);
void setPlayerName(Player *player, int playerNumber);
void setPlayerScore(Player *player);
void printScore(Player *player1, Player *player2);


#endif