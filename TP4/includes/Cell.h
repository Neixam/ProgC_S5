/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 10-11-2020
 *  Modification : 21-11-2020
**/

#ifndef __CELL__
#define __CELL__

typedef struct  s_cell
{
    int             index[2];
    struct s_cell   *next;
}               t_cell,
                *t_list;

/**
 *  Return a new allocated t_list with the index `index` if we have a problem
 *  with the allocation return NULL
**/
t_list  new_cell(int x, int y);

/**
 *  Return 1 if the new list have been full created and assign in the adress of
 *  t_list `l` use the adress of the `root` of this list for look if a new
 *  element have been also created the pos (`x`, `y`) is the index in the `box`
 *  add every adjacent element and the same `level` of this pos in the list,
 *  return 0 if an error is occured in new_cell()
**/
int     new_list(t_list *l, t_list *root, int box[][6], int x, int y, int level);

/**
 *  Check if the chain `l` is bigger than 3 elements
**/
int     chain_bigger_3(t_list l);

/**
 *  Free the list in the adress t_list `l`
**/
void    free_list(t_list *l);

#endif
