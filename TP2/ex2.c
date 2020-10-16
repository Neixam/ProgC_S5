/* Auteur       : Bourennane Amine
*  Creation     : 06-10-2020
*  Modification : 06-10-2020   */
#include <stdio.h>

void	harmonics_series(long int n_iter, long int range)
{
	double      u; /* La valeur en float est ~ 2 097 000 */
    double      u_prv;
	long int    i;

	for (i = 2, u = 1.0, u_prv = 0; i <= n_iter && u != u_prv; i++)
	{
		if (i % range == 0)
			printf("%ld : %f\n", i, u);
        u_prv = u;
		u += 1.0 / ((double) i);
	}
}

int		main(void)
{
	harmonics_series(100000000000, 1000000);
	return (0);
}
