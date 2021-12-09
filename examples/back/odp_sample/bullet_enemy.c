#include "bullet_enemy.h"

void bullet_enemy (Bullets* bullets, Enemies* enemies)
{
    for (int i = 0; i < bullets->n; i++)
    {
        for (int j = 0; j < enemies->n; j++)
        {
            if (bullets->obj[bullets->exist[i]].pos->x == enemies->obj[enemies->exist[j]].pos->x)
            {
                bullets->obj[bullets->exist[i]].hit = true;
                reduce_bullet (bullets, i);

                enemies->obj[enemies->exist[j]].hit = true;
                blast_enemy (&enemies->obj[enemies->exist[j]]);
                reduce_enemy (enemies, j);
            }
            // if a box exist blast for bullets and enemies write code here
        }
    }
}
