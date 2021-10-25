/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 21-11-2020
 *  Modification : 21-11-2020
**/
#include "Location.h"
#include <MLV/MLV_all.h>

/**
 *  Return the max level in `tab`
**/
int         max_level(int tab[][6])
{
    int     i;
    int     j;
    int     max;

    for (max = tab[0][0], i = 0; i < 8; i++)
    {
        for (j = 0; j < 6; j++)
        {
            if (max < tab[i][j])
                max = tab[i][j];
        }
    }
    return (max);
}

/**
 *  Return a new t_location for the 2 new balls, use the `tab` for choose the
 *  level
**/
t_location  new_balls(int tab[][6], int vertical)
{
    t_location  ret;
    int         max;

    max = max_level(tab);
    if (max > 2)
    {
        ret.right_level = MLV_get_random_integer(1, max - 1);
        ret.left_level = MLV_get_random_integer(1, max - 1);
    }
    else
    {
        ret.right_level = 1;
        ret.left_level = 1;
    }
    ret.alignment = MLV_get_random_boolean();
    if (vertical == 5)
        ret.alignment = 1;
    ret.vertical = vertical;
    return (ret);
}
