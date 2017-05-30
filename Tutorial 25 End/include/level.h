#ifndef LEVEL_H
#define LEVEL_H


#include "position.h"
#include "monster.h"
#include "player.h"
#include "room.h"




typedef struct Level
{
    char ** tiles;
    int level;
    int numberOfRooms;
    struct Room ** rooms;
    struct Monster ** monsters;
    int numberOfMonsters;
    struct Player * user;
} Level;

void drawLevel(Level * level);

void addMonsters(Level * level);
void moveMonsters(Level * level);


/* level/map functions */
Level * createLevel();
Room ** roomsSetUp();
char ** saveLevelPositions();
void connectDoors(Level * level);

void checkPostion(Position * newPosition, Level * level);


#endif