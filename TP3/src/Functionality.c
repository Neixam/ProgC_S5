/* Auteur       : Bourennane Amine
*  Creation     : 19-10-2020
*  Modification : 03-11-2020   */
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>

void    clear_(void)
{
    clear_history();
}

int     print_current(int offset)
{
    HIST_ENTRY  *hc;

    history_set_pos(offset);
    if (!(hc = current_history()))
        return (1);
    printf("%s\n", hc->line);
    return (0);
}

void    all_(int offset)
{
    HIST_ENTRY  **hl;
    int         i;

    hl = history_list();
    for (i = offset; i >= 0; i--)
        printf("%s\n", hl[i]->line);
}

int     reverse(int offset)
{
    HIST_ENTRY  *hist_move;

    if (offset < 1)
        return (1);
    hist_move = remove_history(offset - 1);
    add_history(hist_move->line);
    free_history_entry(hist_move);
    return (0);
}

int     funct(int offset, char f)
{
    switch (f)
    {
        case 'p' :  return (print_current(offset));
        case 'c' :  clear_(); return (0);
        case 'a' :  all_(offset); return (0);
        case 'r' :  return (reverse(offset));
        case 'q' :  clear_(); return (77);
    }
    return (0);
}
