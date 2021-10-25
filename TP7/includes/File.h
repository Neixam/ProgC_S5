/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 14-12-2020
 *  Modification : 14-12-2020
**/

#ifndef __FILE_H_
#define __FILE_H_

typedef struct  s_file
{
    long int    size;
    char        *fpath;
}               t_file;

/**
 *  Free tab and set size at 0
**/
void	reset_tab();

/**
 *  Display 10 or less entry of tab
**/
void	print_tab();

/**
 *  Add new element in tab and increment the size of tab, if alloc fail return -1
 *  else 0
**/
int		add_file(const char *fpath, long int size);

#endif
