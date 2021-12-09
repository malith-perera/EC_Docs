#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>
#include "system.h"

typedef struct {
    Position* pos;
    Velocity* vel;
    int life;
    bool hit;
    bool exist;
} Player;


typedef struct {
    int n;
    int* exist;
    Player *obj;
} Players;

#endif // PLAYER_H
