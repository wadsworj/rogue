#ifndef GAME_H
#define GAME_H

#include "level.h"

typedef struct Game
{
    struct Level * levels[10];
    int currentLevel;
} Game;

void render(Game * game);
void gameLoop(Game * game);

#endif