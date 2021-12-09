#include <stdlib.h>

#include "player.h"


Player* create_player (int n)
{
    Player* obj = (Player*) malloc (sizeof (Player) * n);

    return obj;
}


Players* create_players (int n)
{
    Players* obj = (Players*) malloc (sizeof (Players));

    obj->n = n;
    obj->exist = (int*) malloc (sizeof (int) * n);
    obj->obj = (Player*) malloc (sizeof (Player) * n);

    return obj;
}


void reduce_player (Players* obj, int reduce_index)
{
    obj->exist[reduce_index] = obj->exist[--obj->n];
}


void delete_player (Player* obj)
{
    free (obj);
}


void delete_players (Players* obj)
{
    free (obj->exist);
    free (obj->obj);
    free (obj);
}
