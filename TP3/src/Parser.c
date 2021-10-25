/* Auteur       : Bourennane Amine
*  Creation     : 19-10-2020
*  Modification : 03-11-2020   */
#include "Parser.h"
#include "Calc.h"
#include "Functionality.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void    print_error(int type_err, char error, const char *exec)
{
    switch (type_err)
    {
        case (1) : fprintf(stderr, "%s: stack empty\n", exec); break;
        case (2) : fprintf(stderr, "%s: '%c' unimplemented\n", exec, error); break;
        default : fprintf(stderr, "%s: divide by zero\n", exec);
    }
}

int     parser(char *line, const char *exec)
{
    int     i;
    int     j;
    int     err;
    char    op[8] = "*/-+%!^";
    char    f_op[6] = "qpacr";
    char    value[16];
    char    *ret;
    
    using_history();
    for (i = 0; line[i]; i++)
    {
        if (line[i] <= '9' && line[i] >= '0')
        {
            for (j = 0; line[i + j] && line[i + j] <= '9' && line[i + j] >= '0'; j++)
                value[j] = line[i + j];
            value[j] = '\0';
            snprintf(value, 16, "%d", atoi(value));
            add_history(value);
            next_history();
            i += j - 1;
        }
        else if ((ret = strchr(op, line[i])))
        {
            if ((err = calc(where_history() - 1, ret[0])))
                print_error(err, 0, exec);
        }
        else if ((ret = strchr(f_op, line[i])))
        {
            if ((err = funct(where_history() - 1, ret[0])))
            {
                if (err == 77)
                    return (1);
                print_error(err, 0, exec);
            }
        }
        else if (!strchr(" \t\n", line[i]))
            print_error(2, line[i], exec);
    }
    return (0);
}

int     dc(const char *exec)
{
    char        *line;

    for (line = NULL; (line = readline(NULL)); line = NULL)
    {
        if (parser(line, exec))
        {
            free(line);
            break;
        }
        free(line);
    }
    return (0);
}
