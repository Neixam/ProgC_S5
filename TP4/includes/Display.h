/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 10-11-2020
 *  Modification : 21-11-2020
**/

#ifndef __DISPLAY__
#define __DISPLAY__
#include "Board.h"

typedef struct  s_window
{
    unsigned int    width;
    unsigned int    height;
}               t_window;

/**
 *  Display a new window Alchemist with size at 1080x720
**/
void    display_window(void);

/**
 *  Display the board in t_board `b` with a proportionnal size of width and
 *  height in fields of t_window `win` with the width of board `end_x` and the
 *  height of board `end_y`
**/
void    display_board(t_board b, t_window win, int end_x, int end_y);

/**
 *  Display the score in `score` on t_window `win`
**/
void    display_score(int score, t_window win);

/**
 *  Display the instant game in t_board `b`
**/
void    display_game(t_board b);

/**
 *  Close the window
**/
void    close_win(void);

/**
 *  Display the screen for losers, display also the score of the game in `b`
**/
void    display_lose_screen(t_board b);

#endif
