/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 04-01-2021
 *  Modification : 04-01-2021
**/

int     eval(int *args)
{
    return (args[0] - args[1]);
}

int     arity(void)
{
    return (2);
}

char    symbol(void)
{
    return ('-');
}
