/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 04-01-2021
 *  Modification : 04-01-2021
**/
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "Stack.h"
#include "Parsing.h"
#include "Plugins.h"

/**
 *  Return 1 if `c` is between the ascii code of 0 and 9, else 0
**/
int     is_num(int c)
{
    return (c <= '9' && c >= '0');
}

/**
 *  Return the index of the char `c` in the string 's' if no occurence return -1
**/
int     istrchr(const char *s, char c)
{
    int     i;

    for (i = 0; s[i]; i++)
        if (s[i] == c)
            return (i);
    return (-1);
}

/**
 *  Parse the execution in the string `line`, print the unimplemented function
 *  and `exec` which is the name of program return 1 if in the string line have
 *  char q, else if the memory allocation is failed return 2 else return 0
**/
int     parser(char *line, char *exec)
{
    t_funct dc_funct[5] = { stack_top, stack_clear, 
        stack_reverse, stack_display, stack_clear };
    int     i;
    int     val;
    int     index;

    for (i = 0; line[i]; i++)
    {
        if (is_num(line[i]))
        {
            for (val = 0; line[i] && is_num(line[i]); i++)
                val = val * 10 + (line[i] - '0');
            if (!stack_push(val))
                return (2);
            if (!line[i])
                break;
        }
        else if ((index = istrchr("pcraq", line[i])) != -1)
        {
            dc_funct[index]();
            if (index == 4)
                return (1);
        }
        else if (!strchr(" \n\t", line[i]))
        {
            if (!apply_operation(line[i]))
                fprintf(stderr, "%s: '%c' (%d) unimplemented\n", exec, line[i], line[i]);
        }
    } 
    return (0);
}

/**
 *  Recover the line input by the user `exec` is the name of program return 1
 *  if memory allocation is failed, else return 0
**/
int     dc(char *exec)
{
    char    *line;
    int     ret;

    for (line = NULL; (line = readline(NULL)); line = NULL)
    {
        if ((ret = parser(line, exec)))
        {
            free(line);
            if (ret == 2)
            {
                stack_clear();
                return (1);
            }
            break;
        }
        free(line);
    }
    clear_history();
    return (0);
}
