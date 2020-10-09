/* Auteur       : Bourennane Amine
*  Creation     : 05-10-2020
*  Modification : 05-10-2020   */
#include <stdio.h>
#include <stdlib.h>
#define BUFF_SIZE 1024

/* Write in stderr which one type error and return the # of error */
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

/* Write on adresse of FILE* 'out' the content of FILE* 'in', if an error was
 * occured in fprintf() the function return 1 else return 0 */
int     mytee(FILE **out, FILE *in)
{
    char    tmp[BUFF_SIZE];

    while (fgets(tmp, BUFF_SIZE, in))
        if (fprintf(*out, "%s", tmp) < 0)
            return (1);
    return (0);
}

int     main(int ac, char **av)
{
    FILE    *out;
	FILE	*save; /* save stdin */
    char    tmp[BUFF_SIZE];
    int     i;

    if (ac >= 2)
    {
        for (i = 1; i < ac; i++) /* write on all file in argument */
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
        if (ac > 2)
            fclose(save);
    }
	while (fgets(tmp, BUFF_SIZE, (ac >= 2) ? save : stdin)) /* write stdin on stdout */
		if (!printf("%s", tmp))
			return (print_error(2));
    return (0);
}
