#ifndef ENEMY_H
#define ENEMY_H

#include <stdbool.h>
#include "system.h"

typedef struct {
    Position* pos;
    Velocity* vel;
    int life;
    bool hit;
    bool exist;
} Enemy;


typedef struct {
    int n;
    int* exist;
    Enemy *obj;
} Enemies;


void reduce_enemy (Enemies* obj, int reduce_index);
void blast_enemy (Enemy* obj);

#endif // ENEMY_H
