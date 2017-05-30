#include "rogue.h"
#include "mainMenu.h"
#include "game.h"
#include "utils.h"


void menuLoop()
{
    int choice;
    char * choices[] = {"Start Game", "End Game"};

    Game game;
    game.currentLevel = 0;

    while (true)
    {
        choice = mainMenu(2, choices);

        switch (choice)
        {
            case START_GAME:
                gameLoop(&game);
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