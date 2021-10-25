/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 04-01-2021
 *  Modification : 04-01-2021
**/

#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

static t_stack  stack = NULL;
static int      size = 0;

/**
 *  Create a new element of stack with value `data` if memory allocation is
 *  failed return NULL
**/
static t_stack  new_elem(int data)
{
    t_stack ret;

    if (!(ret = (t_stack)malloc(sizeof(t_elem))))
        return (NULL);
    ret->data = data;
    ret->next = NULL;
    return (ret);
}

/**
 *  Return the size of static stack
**/
int             stack_size(void)
{
    return (size);
}

/**
 *  Add a new value `data` in the static stack on the top, return 0 if memory
 *  allocation is failed, return 1 else
**/
int             stack_push(int data)
{
    t_stack tmp;

    tmp = stack;
    if (!(stack = new_elem(data)))
        return (0);
    stack->next = tmp;
    size++;
    return (1);
}

/**
 *  Pop the top of the static stack and return the value in the top
**/
int             stack_pop(void)
{
    t_stack tmp;
    int     ret;

    if (!stack)
        return (0);
    tmp = stack;
    stack = stack->next;
    ret = tmp->data;
    free(tmp);
    size--;
    return (ret);
}

/**
 *  Print the top of the static stack
**/
void            stack_top(void)
{
    if (!stack)
    {
        fprintf(stderr, "stack is empty\n");
        return ;
    }
    printf("%d\n", stack->data);
}

/**
 *  Print the current static stack
**/
void            stack_display(void)
{
    t_stack tmp;

    for (tmp = stack; tmp; tmp = tmp->next)
        printf("%d\n", tmp->data);
}

/**
 *  Reverse the 2 top of the static stack
**/
void            stack_reverse(void)
{
    t_stack next;

    if (!stack || !stack->next)
    {
        fprintf(stderr, "stack is empty\n");
        return ;
    }
    next = stack->next;
    stack->next = next->next;
    next->next = stack;
    stack = next;
}

/**
 *  Free the stack in adress of t_stack 's'
**/
static void     free_stack(t_stack *s)
{
    if (!*s)
        return ;
    free_stack(&(*s)->next);
    free(*s);
    *s = NULL;
}

/**
 *  Free the static stack
**/
void            stack_clear(void)
{
    free_stack(&stack);
}
