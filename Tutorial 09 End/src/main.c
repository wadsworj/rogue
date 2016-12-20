#include "rogue.h"

int main ()
{
    Player * user;
    int ch;

    screenSetUp();

    mapSetUp();

    user = playerSetUp();

    /* main game loop */
    while ((ch = getch()) != 'q')
    {
        handleInput(ch, user);

    }
    endwin();

    return 0;
}


int screenSetUp()
{
    initscr();
    printw("Hello world!");
    noecho();
    refresh();

    srand(time(NULL));

    return 1;

}

Room ** mapSetUp()
{
    Room ** rooms;
    rooms = malloc(sizeof(Room)*6);

    rooms[0] = createRoom(13, 13, 6, 8);
    drawRoom(rooms[0]);

    rooms[1] = createRoom(40, 2, 6, 8);
    drawRoom(rooms[1]);

    rooms[2] = createRoom(40, 10, 6, 12);
    drawRoom(rooms[2]);

    connectDoors(rooms[0]->doors[3], rooms[2]->doors[1]);

    connectDoors(rooms[1]->doors[2], rooms[0]->doors[0]);

    return rooms;
}
