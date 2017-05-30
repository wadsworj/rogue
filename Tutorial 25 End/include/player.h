#ifndef PLAYER_H
#define PLAYER_H

#include "position.h"

typedef struct Player
{
    Position * position;
    int health;
    int attack;
    int gold;
    int maxHealth;
    int exp;
    // Room * room;
} Player;

/* player functions */
Player * playerSetUp();
Position * handleInput(int input, Player * user);
void playerMove(Position * newPosition, Player * user, char ** level);
void drawPlayer(Player * player);


#endif