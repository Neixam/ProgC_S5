/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 04-01-2021
 *  Modification : 04-01-2021
**/

static int  ft_exp(int a, int n)
{
    if (n < 0)
        return (0);
    if (n == 0)
        return (1);
    return (a * ft_exp(a, n - 1));
}

int     eval(int *args)
{
    return (ft_exp(args[0], args[1]));
}

int     arity(void)
{
    return (2);
}

char    symbol(void)
{
    return ('^');
}
