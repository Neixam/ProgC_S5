/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 10-11-2020
 *  Modification : 21-11-2020
**/
#include <stdlib.h>
#include "Cell.h"
#include "Board.h"

/**
 *  Return a new allocated t_list with the index `index` if we have a problem
 *  with the allocation return NULL
**/
t_list  new_cell(int x, int y)
{
    t_list  ret;

    if (!(ret = (t_list)malloc(sizeof(t_cell))))
        return (NULL);
    ret->index[0] = y;
    ret->index[1] = x;
    ret->next = NULL;
    return (ret);
}

/**
 *  Check if the chain `l` is bigger than 3 elements
**/
int     chain_bigger_3(t_list l)
{
    int     count;

    for (count = 0; l; count++, l = l->next)
        if (count >= 2)
            return (1);
    return (0);
}

/**
 *  Look in the list `l` if the element (`x`, `y`) is already there
**/
int     in_lst(t_list l, int x, int y)
{
    for (; l; l = l->next)
        if (l->index[0] == y && l->index[1] == x)
            return (1);
    return (0);
}

/**
 *  Return 1 if the new list have been full created and assign in the adress of
 *  t_list `l` use the adress of the `root` of this list for look if a new
 *  element have been also created the pos (`x`, `y`) is the index in the `box`
 *  add every adjacent element and the same `level` of this pos in the list,
 *  return 0 if an error is occured in new_cell()
**/
int     new_list(t_list *l, t_list *root, int box[][6], int x, int y, int level)
{
    if (x >= X || y >= Y || y < 0 || x < 0)
        return (1);
    if (box[y][x] == level)
    {
        if (*l != NULL)
            free_list(l);
        if (!(*l = new_cell(x, y)))
            return (0);
    }
    else
        return (1);
    return ((in_lst(*root, x + 1, y) || new_list(&(*l)->next, root, box,
        x + 1, y, level)) &&
        (in_lst(*root, x - 1, y) || new_list(&(*l)->next, root, box,
        x - 1, y, level)) &&
        (in_lst(*root, x, y + 1) || new_list(&(*l)->next, root, box,
        x, y + 1, level)) &&
        (in_lst(*root, x, y - 1) || new_list(&(*l)->next, root, box,
        x, y - 1, level)));
}

/**
 *  Free the list in the adress t_list `l`
**/
void    free_list(t_list *l)
{
    if (*l == NULL)
        return ;
    free_list(&(*l)->next);
    free(*l);
}
