/* Auteur       : Bourennane Amine
*  Creation     : 05-10-2020
*  Modification : 05-10-2020   */
#include <stdio.h>
#include <stdlib.h>
#define BUFF_SIZE 1024

int     print_error(int type_error)
{
    switch (type_error)
    {
        case (1) : fprintf(stderr, "Pas le droit d'accès au fichier.\n");
                   break;
        case (2) : fprintf(stderr, "Impossible d'écrire dans le fichier.\n");
                   break;
        default : ;
    }
    return (type_error);
}

int     mytee(FILE **out, FILE *in)
{
    char    tmp[BUFF_SIZE];

    while (fgets(tmp, BUFF_SIZE, in))
        if (!fprintf(*out, "%s", tmp))
            return (1);
    return (0);
}

int     main(int ac, char **av)
{
    FILE    *out;
	FILE	*save;
    char    tmp[BUFF_SIZE];
    int     i;

    if (ac >= 2)
    {
        for (i = 1; i < ac; i++)
        {
            if (!(out = fopen(av[i], "w")))
                return (print_error(1));
            if (mytee(&out, (i == 1) ? stdin : save))
                return (print_error(2));
			fclose(out);
			if (i == 1)
				if (!(save = fopen(av[1], "r")))
					return (print_error(1));
			rewind(save);
        }
		
    }
	while (fgets(tmp, BUFF_SIZE, (ac >= 2) ? save : stdin))
		if (!printf("%s", tmp))
			return (print_error(2));
    return (0);
}
