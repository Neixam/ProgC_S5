/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 10-11-2020
 *  Modification : 21-11-2020
**/

#ifndef __BOARD__
#define __BOARD__
#define Y 8
#define X 6
#include "Location.h"

typedef struct  s_board
{
    int         box[Y][X];
    int         score;
    t_location  loc;
}               t_board;

typedef int (*t_deed)(t_board*); /* reachable action */

/**
 *  Update the board in the adress of t_board `b` return 0 if there are an error
 *  1 else
**/
int     update_board(t_board *b);

/**
 *  Main function call all function of program, return 1 if encounter a process 
 *  error else 0
**/
int     game(void);

#endif
