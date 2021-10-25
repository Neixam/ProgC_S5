/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 04-01-2021
 *  Modification : 04-01-2021
**/

static int  ft_fac(int a)
{
    if (a < 0)
        return (0);
    if (a < 2)
        return (1);
    return (a * ft_fac(a - 1));
}

int         eval(int *args)
{
    return (ft_fac(args[0]));
}

int     arity(void)
{
    return (1);
}

char    symbol(void)
{
    return ('!');
}
