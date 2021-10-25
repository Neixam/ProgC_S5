/* Auteur       : Bourennane Amine
*  Creation     : 19-10-2020
*  Modification : 03-11-2020   */
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>

int     add(int a, int b)
{
    return (a + b);
}

int     sub(int a, int b)
{
    return (a - b);
}

int     mul(int a, int b)
{
    return (a * b);
}

int     div_(int a, int b)
{
    return (a / b);
}

int     mod(int a, int b)
{
    return (a % b);
}

int     expo(int a, int b)
{
    int     res;
    int     i;

    for (i = 0, res = 1; i < b; i++)
        res *= a;
    return (res);
}

int     fact(int a)
{
    if (a < 0)
        return (0);
    if (a < 2)
        return (1);
    return (a * fact(a - 1));
}

int     calc(int offset, char op)
{
    HIST_ENTRY  *hc;
    HIST_ENTRY  *hc_prev;
    int         res;
    int         a;
    int         b;
    char        nw_line[16];

    history_set_pos(offset);
    if (!(hc = current_history()))
        return (1);
    b = atoi(hc->line);
    if (op == '!')
    {
        res = fact(b);
        snprintf(nw_line, 16, "%d", res);
        free_history_entry(replace_history_entry(offset, nw_line, hc->data));
        return (0);
    }
    if (!(hc_prev = previous_history()))
        return (1);
    a = atoi(hc_prev->line);
    switch (op)
    {
        case '*' :  res = mul(a, b); break;
        case '-' :  res = sub(a, b); break;
        case '+' :  res = add(a, b); break;
        case '^' :  res = expo(a, b); break;
        case '/' :  if (b == 0) return (3);
                    res = div_(a, b); break;
        case '%' :  if (b == 0) return (3);
                    res = mod(a, b); break;
    }
    snprintf(nw_line, 16, "%d", res);
    free_history_entry(replace_history_entry(offset - 1, nw_line, hc_prev->data));
    free_history_entry(remove_history(offset));
    next_history();
    return (0);
}
