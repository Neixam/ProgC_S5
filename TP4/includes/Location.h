/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 10-11-2020
 *  Modification : 21-11-2020
**/

#ifndef __LOCATION__
#define __LOCATION__

typedef struct  s_location
{
    int     alignment;
    int     vertical;
    int     left_level;
    int     right_level;
}               t_location;

/**
 *  Return a new t_location for the 2 new balls, use the `tab` for choose the
 *  level
**/
t_location  new_balls(int tab[][6], int vertical);

#endif
