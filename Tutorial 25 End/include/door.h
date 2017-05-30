#ifndef DOOR_H
#define DOOR_H

#include "position.h"


typedef struct Door
{
    Position position;
    int connected;
} Door;


#endif
