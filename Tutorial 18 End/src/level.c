#include "rogue.h"

// typedef struct Level
// {
//     char ** tiles;
//     int numberOfRooms;
//     struct Room ** rooms;
//     struct Monster ** monsters;
//     int numberOfMonsters;
// } Level;


Level * createLevel(int level)
{
    Level * newLevel;
    newLevel = malloc(sizeof(Level));

    newLevel->level = level;
    newLevel->numberOfRooms = 3;
    newLevel->rooms = roomsSetUp();
    newLevel->tiles = saveLevelPositions();

    newLevel->user = playerSetUp();
    placePlayer(newLevel->rooms, newLevel->user);

    addMonsters(newLevel);

    return newLevel;
}

Room ** roomsSetUp()
{
    int x;
    Room ** rooms;
    rooms = malloc(sizeof(Room)*6);

    for (x = 0; x < 6; x++)
    {
        rooms[x] = createRoom(x);
        drawRoom(rooms[x]);
    }
    connectDoors(rooms[0]->doors[3], rooms[1]->doors[1]);

    connectDoors(rooms[1]->doors[2], rooms[0]->doors[0]);

    return rooms;
}


char ** saveLevelPositions()
{
    int x, y;
    char ** positions;
    positions = malloc(sizeof(char *) * 25);

    for (y = 0; y < 25; y++)
    {
        positions[y] = malloc(sizeof(char) * 100);
        for (x = 0; x < 100; x++)
        {
            positions[y][x] = mvinch(y, x);
        }
    }

    return positions;
}