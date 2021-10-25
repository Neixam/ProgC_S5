/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 14-12-2020
 *  Modification : 14-12-2020
**/

#include "File.h"
#include "Mystrdup.h"
#include <stdlib.h>
#include <stdio.h>
#define MAX_PRINT 10

static t_file   all_file[MAX_PRINT];
static int      len = 0;

/**
 *  Return 1 if a < b 0 else
**/
int     file_size_cmp(const void *a, const void *b)
{
    t_file  *f1 = (t_file*) a;
    t_file  *f2 = (t_file*) b;
    return (f1->size < f2->size);
}


/**
 *  Display 10 or less entry of tab
**/
void    print_tab()
{
    int     i;

    for (i = 0; i < len; i++)
        printf("%s : %ld octets\n", all_file[i].fpath, all_file[i].size);
}

/**
 *  Free tab and set size at 0
**/
void    reset_tab()
{
    int     i;

    for (i = 0; i < len; i++)
        free(all_file[i].fpath);
    len = 0;
}

/**
 *  Add new element in tab and increment the size of tab, if alloc fail return -1
 *  else 0
**/
int     add_file(const char *fpath, long int size)
{
    if (len < MAX_PRINT)
    {
        all_file[len].size = size;
        if (!(all_file[len].fpath = ft_strdup(fpath)))
            return (-1);
        len++;
    }
    else
    {
        if (all_file[len - 1].size < size)
        {
            all_file[len - 1].size = size;
            free(all_file[len - 1].fpath);
            if (!(all_file[len - 1].fpath = ft_strdup(fpath)))
                return (-1);
        }
    }
    qsort(all_file, len, sizeof(t_file), file_size_cmp);
    return (0);
}
