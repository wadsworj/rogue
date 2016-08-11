#include "rogue.h"

Player * playerSetUp()
{
    Player * newPlayer;
    newPlayer = malloc(sizeof(Player));
    newPlayer->position = malloc(sizeof(Position));

    newPlayer->health = 20;
    newPlayer->attack = 1;
    newPlayer->gold = 0;
    newPlayer->exp = 0;
    newPlayer->maxHealth = 20;
    
    return newPlayer;
}

int placePlayer(Room ** rooms, Player * user)
{
    user->position->x = rooms[3]->position.x + 1;
    user->position->y = rooms[3]->position.y + 1;

    mvprintw(user->position->y, user->position->x, "@");
    move(user->position->y, user->position->x);
}

Position * handleInput(int input, Player * user)
{
    Position * newPosition;
    newPosition = malloc(sizeof(Position));
    switch (input)
    {
        /* move up */
        case 'w':
        case 'W':
            newPosition->y = user->position->y - 1;
            newPosition->x = user->position->x;
            break;

        /* move down */
        case 's':
        case 'S':
            newPosition->y = user->position->y + 1;
            newPosition->x = user->position->x;
            break;

        /* move left */
        case 'a':
        case 'A':
            newPosition->y = user->position->y;
            newPosition->x = user->position->x - 1;
            break;

        /* move right */
        case 'd':
        case 'D':
            newPosition->y = user->position->y;
            newPosition->x = user->position->x + 1;
            break;

        default:
            break;

    }

    return newPosition;

}

/* check what is at next position */
int checkPostion(Position * newPosition, Level * level)
{
    Player * user;
    user = level->user;
    int space;
    switch (mvinch(newPosition->y, newPosition->x))
    {
        case '.':
        case '#':
        case '+':
            playerMove(newPosition, user, level->tiles);
            break;
        case 'X':
        case 'G':
        case 'T':
            combat(user, getMonsterAt(newPosition, level->monsters), 1);
        default:
            move(user->position->y, user->position->x);
            break;
    }

}

int playerMove(Position * newPosition, Player * user, char ** level)
{
    char buffer[8];

    sprintf(buffer, "%c", level[user->position->y][user->position->x]);

    mvprintw(user->position->y, user->position->x, buffer);

    user->position->y = newPosition->y;
    user->position->x = newPosition->x;

    mvprintw(user->position->y, user->position->x, "@");
    move(user->position->y, user->position->x);


}