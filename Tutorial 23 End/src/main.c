#include "rogue.h"
#include "mainMenu.h"

int gameLoop()
{
    int ch;
    Position * newPosition;
    Level * level;

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

        if (level->user->health <= 0)
        {
            return -1;
        }
    }
}

void menuLoop()
{
    int choice;
    char * choices[] = {"Start Game", "End Game"};

    while (true)
    {
        choice = mainMenu(2, choices);

        switch (choice)
        {
            case START_GAME:
                gameLoop();
                clear();
                break;
            case QUIT_GAME:
                return;
                break;
        }
    }
}

int main ()
{
    screenSetUp();
    menuLoop();
    endwin();

    return 0;
}