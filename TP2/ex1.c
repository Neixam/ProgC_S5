/* Auteur       : Bourennane Amine
*  Creation     : 06-10-2020
*  Modification : 06-10-2020   */
#include <stdio.h>

int     is_rigolo(char n[])
{
    int     value;

    value = (n[0] * 100) + (n[1] * 10) + n[2];
    if ((n[0] * n[0] * n[0]) + (n[1] * n[1] * n[1]) + (n[2] * n[2] * n[2]) == value)
        return (1);
    return (0);
}

void    whose_rigolo(void)
{
    char    n[3] = {0};

    for (n[0] = 0; n[0] < 5; n[0]++)
    {
        for (n[1] = 0; n[1] <= 9; n[1]++)
        {
            for (n[2] = 0; n[2] <= 9; n[2]++)
                if (is_rigolo(n))
                    printf("%c%c%c\n", n[0] + '0', n[1] + '0', n[2] + '0');
        }
    }
}

int     main(void)
{
    whose_rigolo();
    return (0);
}
