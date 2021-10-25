/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 04-01-2021
 *  Modification : 04-01-2021
**/
#ifndef __STACK__
#define __STACK__

typedef struct  s_stack
{
    int             data;
    struct s_stack  *next;
}               t_elem,
                *t_stack;

/**
 *  Add a new value `data` in the static stack on the top, return 0 if memory
 *  allocation is failed, return 1 else
**/
int     stack_push(int data);

/**
 *  Pop the top of the static stack and return the value in the top
**/
int		stack_pop(void);

/**
 *  Return the size of static stack
**/
int     stack_size(void);

/**
 *  Print the top of the static stack
**/
void    stack_top(void);

/**
 *  Print the current static stack
**/
void    stack_display(void);

/**
 *  Reverse the 2 top of the static stack
**/
void    stack_reverse(void);

/**
 *  Free the static stack
**/
void    stack_clear(void);

#endif
