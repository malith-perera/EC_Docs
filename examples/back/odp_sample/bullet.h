#ifndef BULLET_H
#define BULLET_H

#include <stdbool.h>
#include "system.h"

typedef struct {
    Position* pos;
    Velocity* vel;
    int power;
    bool hit;
    bool exist;
} Bullet;


typedef struct {
    int n;
    int* exist;
    Bullet *obj;
} Bullets;


void reduce_bullet (Bullets* obj, int reduce_index);

#endif // BULLET_H
