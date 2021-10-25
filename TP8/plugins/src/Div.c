/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 04-01-2021
 *  Modification : 04-01-2021
**/

#include <stdio.h>

int     eval(int *args)
{
    if (args[1] == 0)
    {
        fprintf(stderr, "divide by 0\n");
        return (0);
    }
    return (args[0] / args[1]);
}

int     arity(void)
{
    return (2);
}

char    symbol(void)
{
    return ('/');
}
