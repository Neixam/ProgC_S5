/* Auteur       : Bourennane Amine
*  Creation     : 06-10-2020
*  Modification : 06-10-2020   */
#include <stdio.h>

void	harmonics_series(long int n_iter, long int range)
{
	double     u; /* La valeur en float est ~ 2 097 000 */
	long int   i;

	u = 1.0;
	for (i = 2; i <= n_iter; i++)
	{
		if (i % range == 0)
			printf("%ld : %f\n", i, u);
		u += 1.0 / ((double) i);
	}
}

int		main(void)
{
	harmonics_series(100000000000, 1000);
	return (0);
}
