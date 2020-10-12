/* Auteur       : Bourennane Amine
*  Creation     : 12-10-2020
*  Modification : 12-10-2020   */
#include <stdio.h>
#include <string.h>

void    mirroir_string(char *s)
{
    int     i;
    int     j;
    char    tmp;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

int     main(int ac, char **av)
{
    int     i;

    for (i = 1; i < ac; i++)
    {
        mirroir_string(av[i]);
        printf("%s\n", av[i]);
    }
    return (0);
}
