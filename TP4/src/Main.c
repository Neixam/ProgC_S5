/** 
 *  Auteur       : Bourennane Amine
 *  Creation     : 10-11-2020
 *  Modification : 21-11-2020
**/
#include "Board.h"
#include <stdio.h>

int     main(int ac, char **av)
{
    if (game())
    {
        fprintf(stderr, "Error of allocation\n");
        return (1);
    }
    return (0);
}
