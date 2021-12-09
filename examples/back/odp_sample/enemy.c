#include <stdlib.h>

#include "enemy.h"


Enemy* create_enemy (int n)
{
    Enemy* obj = (Enemy*) malloc (sizeof (Enemy) * n);

    return obj;
}


Enemies* create_enemies (int n)
{
    Enemies* obj = (Enemies*) malloc (sizeof (Enemies));

    obj->n = n;
    obj->exist = (int*) malloc (sizeof (int) * n);
    obj->obj = (Enemy*) malloc (sizeof (Enemy) * n);

    return obj;
}


void reduce_enemy (Enemies* obj, int reduce_index)
{
    obj->exist[reduce_index] = obj->exist[--obj->n];
}


void delete_enemy (Enemy* obj)
{
    free (obj);
}


void delete_enemies (Enemies* obj)
{
    free (obj->exist);
    free (obj->obj);
    free (obj);
}


void blast_enemy (Enemy* obj)
{
    printf ("enemy blasted\n");
}
