/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 14-12-2020
 *  Modification : 14-12-2020
**/

#include "Mystrdup.h"
#include <stdlib.h>
#include <string.h>

/**
 *  Return a new allocated copy of string `s` with nul terminated character else
 *	return NULL if have an allocation error
**/
char    *ft_strdup(const char *s)
{
    char    *ret;
    int     i;

    if (!(ret = (char*) malloc(sizeof(char) * (strlen(s) + 1))))
        return (NULL);
    for (i = 0; *s; i++, s++)
        ret[i] = (char) *s;
    ret[i] = 0;
    return (ret);
}
