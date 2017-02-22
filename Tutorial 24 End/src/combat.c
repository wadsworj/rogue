#include "rogue.h"

int combat(Player * player, Monster * monster, int order)
{
    /* player attacking */
    if (order == 1)
    {
        monster->health -= player->attack;
        if (monster->health > 0)
        {
            player->health -= monster->attack;
        }
        else
        {
            killMonster(monster);
            player->exp++;
        }
    }
    /* monster attacking */
    else
    {
        player->health -= monster->attack;
        if (player->health > 0)
        {
            monster->health -= player->attack;
        }
    }

    return 1;
}