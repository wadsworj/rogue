#ifndef ROGUE_H
#define ROGUE_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

typedef struct Position {
    int x;
    int y;
    // TILE_TYPE tile;
} Position;

typedef struct Room
{
    Position position;
    int height;
    int width;

    Position ** doors;
    // Monster ** monsters;
    // Item ** items;
} Room;

typedef struct Player
{
    Position position;
    int health;
    // Room * room;
} Player;

int screenSetUp();
Room ** mapSetUp();
Player * playerSetUp();
int handleInput(int input, Player * user);
int checkPostion(int newY, int newX, Player * user);
int playerMove(int y, int x, Player * user);

/* room functions */
Room * createRoom(int x, int y, int height, int width);
int drawRoom(Room * room);
int connectDoors(Position * doorOne, Position * doorTwo);

#endif