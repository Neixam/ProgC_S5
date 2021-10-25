/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 05-01-2021
 *  Modification : 05-01-2021
**/

#ifndef __PARSING__
#define __PARSING__

#include "Parsing.h"
#include "Plugins.h"

typedef void (*t_funct)(void);

/**
 *  Recover the line input by the user `exec` is the name of program return 1
 *  if memory allocation is failed, else return 0
**/
int     dc(char *exec);

#endif
