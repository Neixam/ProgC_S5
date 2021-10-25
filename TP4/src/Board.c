/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 10-11-2020
 *  Modification : 21-11-2020
**/
#include "Board.h"
#include "Display.h"
#include "Location.h"
#include "Player.h"
#include "Cell.h"
#include <MLV/MLV_event.h>

/**
 *  Return a result of a^n, return 0 if n < 0
**/
int     ft_pow(int a, int n)
{
    if (n < 0)
        return (0);
    if (n == 0)
        return (1);
    return (a * ft_pow(a, n - 1));
}

/**
 *  Initialisation value in an adress of t_board `b`
**/
void    init_board(t_board *b)
{
    int     i;
    int     j;

    for (i = 0; i < Y; i++)
    {
        for (j = 0; j < X; j++)
            b->box[i][j] = 0;
    }
    b->score = 0;
    b->loc = new_balls(b->box, 0);
}

/**
 *  Verify if the ball in (`x`, `y`) have an collision with other same `level`
 *  ball in the t_board `b`, and if we have a collision we make the chain
 *  blow-up and increment the score with a `bonus` and create a new ball level-up
 *  return 0 for report a problem with memory else 1
**/
int     collision_balls(t_board *b, int x, int y, int level, int bonus)
{
    t_list  collision;
    t_list  buff;

    collision = NULL;
    if (!(new_list(&collision, &collision, b->box, x, y, level)))
        return (0);
    if (chain_bigger_3(collision))
    {
        for (buff = collision; buff; buff = buff->next)
        {
            b->score += ft_pow(3, level) * bonus;
            b->box[buff->index[0]][buff->index[1]] = 0;
        }
        b->box[y][x] = level + 1;
    }
    free_list(&collision);
    return (1);
}

/**
 *  Applie a gravity on the ball on pos (`x`, `y`) in the board `b` and verify
 *  if a new collision have been created return 1 if all is good and 0 else
**/
int     gravity(t_board *b, int x, int y, int level)
{
    int     i;
    int     buff_score;

    for (i = y + 1; i < Y && !b->box[i][x]; i++) { }
    b->box[i - 1][x] = level;
    if (y != i - 1)
        b->box[y][x] = 0;
    buff_score = b->score;
    if (!collision_balls(b, x, i - 1, level, 2))
        return (0);
    if (buff_score != b->score)
        return (update_board(b));
    return (1);
}

/**
 *  Update the board in the adress of t_board `b` return 0 if there are an error
 *  1 else
**/
int     update_board(t_board *b)
{
    int     i;
    int     j;

    for (i = Y - 1; i >= 0; i--)
    {
        for (j = X - 1; j >= 0; j--)
        {
            if (b->box[i][j])
            {
                if (!gravity(b, j, i, b->box[i][j]))
                    return (0);
            }
        }
    }
    b->loc = new_balls(b->box, b->loc.vertical);
    return (1);
}

/**
 *  Free the memory and close window and return 2 for indicate at the main
 *  function that the end of program
**/
int     quit(t_board *b)
{
    close_win();
    return (2);
}

/**
 *  Rotation of the 2 news balls
**/
int     turn(t_board *b)
{
    if (b->loc.vertical != X - 1 || !b->loc.alignment)
        b->loc.alignment = (b->loc.alignment) ? 0 : 1;
    return (1);
}

/**
 *  Move sideways to the left the 2 news balls
**/
int     left(t_board *b)
{
    b->loc.vertical -= (b->loc.vertical > 0) ? 1 : 0;
    return (1);
}

/**
 *  Move sideways to the right the 2 news balls
**/
int     right(t_board *b)
{
    b->loc.vertical += ((b->loc.vertical < X - 1 && b->loc.alignment) ||
                (b->loc.vertical < X - 2)) ? 1 : 0; 
    return (1);
}

/**
 *  Insert the news balls in board and update everything that implies
**/
int     fall(t_board *b)
{
    int     i;

    if ((!b->loc.alignment && (b->box[0][b->loc.vertical] ||
            b->box[0][b->loc.vertical + 1])) || (b->loc.alignment &&
            b->box[1][b->loc.vertical]))
        return (1);
    for (i = 0; i < Y && !b->box[i][b->loc.vertical] &&
        (!b->box[i][b->loc.vertical + 1] || b->loc.alignment); i++) { }
    b->box[i - 1][b->loc.vertical] = b->loc.left_level;
    b->box[i - 1 - b->loc.alignment][b->loc.vertical + (b->loc.alignment == 0)] = b->loc.right_level;
    if (!collision_balls(b, b->loc.vertical, i - 1, b->loc.left_level, 1))
        return (0);
    if (b->loc.left_level != b->loc.right_level)
        if (!collision_balls(b, b->loc.vertical + (b->loc.alignment == 0),
                i - 1 - b->loc.alignment, b->loc.right_level, 1))
            return (0);
    return (update_board(b));
}

/**
 *  Return 1 if the state of board in `b` is full return 0 else
**/
int     is_lose(t_board b)
{
    int     i;

    for (i = 0; i < X; i++)
        if ((i + 1 < X && !b.box[0][i] && !b.box[0][i + 1]) ||
            (!b.box[0][i] && !b.box[1][i]))
            return (0);
    return (1);
}

/**
 *  Main function call all function of program, return 1 if encounter a process 
 *  error else 0
**/
int     game(void)
{
    t_board game;
    t_deed  act[5] = { turn, fall, right, left, quit };
    int     ret;

    init_board(&game);
    display_window();
    while (1)
    {
        display_game(game);
        if (!(ret = act[wait_user()](&game)))
            return (1);
        if (ret == 2)
            return (0);
        if (is_lose(game))
        {
            display_lose_screen(game);
            while (wait_user() != 4) { }
            act[4](&game);
            return (0);
        }
    }
    return (0);
}
