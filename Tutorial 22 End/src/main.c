#include "rogue.h"

int main ()
{
    int ch;

    MAX_HEIGHT = 25;
    MAX_WIDTH = 100;
    Position * newPosition;

    Level * level;

    screenSetUp();

    level = createLevel(1);
    printGameHub(level);

    /* main game loop */
    while ((ch = getch()) != 'q')
    {
        printGameHub(level);
        newPosition = handleInput(ch, level->user);
        checkPostion(newPosition, level);
        moveMonsters(level);
        move(level->user->position->y, level->user->position->x);
    }
    endwin();

    return 0;
}