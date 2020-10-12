/* Auteur       : Bourennane Amine
*  Creation     : 12-10-2020
*  Modification : 12-10-2020   */
#include <stdio.h>
#include <string.h>
#define BUFF_SIZE 1024

void    tab(int len)
{
    int     i;

    for (i = 0; i < len / 2; i++)
        printf(" ");
}

int     print_draw(int len)
{
    char    buff[BUFF_SIZE];
    FILE    *draw;

    if (!(draw = fopen(".draw.txt", "r")))
        return (1);
    while (fgets(buff, BUFF_SIZE, draw))
    {
        tab((len + 4 < 11) ? 0 : (len + 4) - 11);
        printf("%s", buff);
    }
    return (0);
}

void    print_msg(char *s, int len)
{
    int     i;

    printf(" _");
    for (i = 0; i <= len; i++)
        printf("_");
    printf("\n< ");
    printf("%s", s);
    printf(" >\n -");
    for (i = 0; i <= len; i++)
        printf("-");
    printf("\n");
}

int     main(int ac, char **av)
{
    int     len;

    if (ac != 2)
        return (1);
    len = strlen(av[1]);
    print_msg(av[1], len);
    if (print_draw(len))
        return (2);
    return (0);
}
