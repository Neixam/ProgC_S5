/* Auteur       : Bourennane Amine
*  Creation     : 06-10-2020
*  Modification : 06-10-2020   */
#include <stdio.h>
#include <stdlib.h>

/* Return gcd('a','b') with Euclidean algorithm */
int         gcd_euclide(long int a, int b)
{
    int     tmp;

    while (b != 0)
    {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return (a);
}

/* Return lcm('a','b') with the formul lcm(a,b) = |a*b| / gcd(a,b) */
int         lcm(long int a, int b)
{
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;
    return ((a * b) / gcd_euclide(a, b));
}

/* Return the lcm of all int in the sequence 'seq' with atoi() */
long int    all_lcm(char **seq, int len)
{
    int         i;
    long int    ret;

    ret = atoi(seq[0]);
    for (i = 1; i < len; i++)
       ret = lcm(ret, atoi(seq[i]));
    return (ret);
}

/* Write in stderr which one type error and return the # of error */
int         print_err(int type_err)
{
    switch (type_err)
    {
        case (1) : fprintf(stderr, "Is not a number\n");
                   break;
        case (2) : fprintf(stderr, "incorrect usage\nusage :./ppcm [number]...\n");
                   break;
        default : ;
    }
    return (type_err);
}

/* Return 1 if all char in 's' are numeric else return 0 */
int         is_all_numeric(char *s)
{
    int     i;

    for (i = 0; s[i] != '\0'; i++)
        if ((s[i] > '9' || s[i] < '0') && s[i] != '-')
            return (0);
    return (1);
}

/* Return 2 if arg are missing, return 1 if one arg is not numeric else return 0  */
int         parsing(int ac, char **av)
{
    int     i;

    if (ac == 1)
        return (2);
    for (i = 1; i < ac; i++)
        if (!is_all_numeric(av[i]))
            return (1);
    return (0);
}

int         main(int ac, char **av)
{
    int         type_err;
    long int    lcm;

    if ((type_err = parsing(ac, av))) /* parse the arguments on stdin */
        return (print_err(type_err));
    lcm = all_lcm(&av[1], ac - 1);
    printf("%ld\n", lcm); /* write in stdout the lcm value */
    return (0);
}
