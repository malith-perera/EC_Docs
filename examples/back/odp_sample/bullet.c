#include <stdlib.h>

#include "bullet.h"


Bullet* create_bullet (int n)
{
    Bullet* obj = (Bullet*) malloc (sizeof (Bullet) * n);

    return obj;
}


Bullets* create_bullets (int n)
{
    Bullets* obj = (Bullets*) malloc (sizeof (Bullets));

    obj->n = n;
    obj->exist = (int*) malloc (sizeof (int) * n);
    obj->obj = (Bullet*) malloc (sizeof (Bullet) * n);

    return obj;
}


void reduce_bullet (Bullets* obj, int reduce_index)
{
    obj->exist[reduce_index] = obj->exist[--obj->n];
}


void delete_bullet (Bullet* obj)
{
    free (obj);
}


void delete_bullets (Bullets* obj)
{
    free (obj->exist);
    free (obj->obj);
    free (obj);
}
