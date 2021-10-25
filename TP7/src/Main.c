/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 14-12-2020
 *  Modification : 14-12-2020
**/

#include <stdio.h>
#include <ftw.h>
#include <sys/stat.h>
#include <unistd.h>
#include <getopt.h>
#include "File.h"

/**
 *  Function callable in ftw() the string `fpath` is the path of current file,
 *	the adress of struct stat `sb` pointed in the file in fpath, the int
 *	`typeflag` indicate the type file is given to fn
**/
int     fn(const char *fpath, const struct stat *sb, int typeflag)
{
    if (typeflag != FTW_F)
        return (0);
    if (add_file(fpath, sb->st_size) == -1)
        return (-4);
    return (0);
}

int     main(int ac, char **av)
{
    int     i;
    int     ret;

    while ((ret = getopt(ac, av, "h")) != -1)
    {
        if (ret == 'h')
        {
            printf("./larger_file [directories]\nprint the ten or less heaviest \
file in directory/root\n");
            return (0);
        }
    } 
    if (ac < 3)
    {
        if ((ret = ftw((ac == 1) ? "." : av[1], fn, MAX_FD)) != 0)
        {
            if (ret != -4)
                print_tab();
            reset_tab();
            return (1);
        }
        print_tab();
        reset_tab();
    }
    else
    {
        for (i = 1; i < ac; i++)
        {
            if ((ret = ftw(av[i], fn, MAX_FD)) != 0)
            {
                if (ret != -4)
                    print_tab();
                reset_tab();
                return (1);
            }
            printf("in %s :\n", av[i]);
            print_tab();
            reset_tab();
        }
    }
    return (0);
}
