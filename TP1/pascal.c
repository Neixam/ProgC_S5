/* Auteur       : Bourennane Amine
*  Creation     : 05-10-2020
*  Modification : 05-10-2020   */
#include <stdlib.h>
#include <stdio.h>

int     binomiaux(int n, int p)
{
    if ((n == p || p == 0))
        return (1);
    if (n > 0 && p > 0 && p < n)
        return (binomiaux(n - 1, p) + binomiaux(n - 1, p - 1));
    return (0);
}

int     affiche_erreur(int type_erreur)
{
    switch (type_erreur)
    {
        case (0) : fprintf(stderr, "L'allocation n'a pas pu se réaliser\n");
                   break;
        case (1) : fprintf(stderr, "Les valeurs de n et p sont incorrectes\n");
                   break;
        default : ;
    }
    return (1);
}

void     binomiaux_bis_aux(int *tab, int n)
{
    int     i;

    for (i = n; i > 0; i--)
        tab[i] += tab[i - 1];
}

int     binomiaux_bis(int n, int p)
{
    int     *tab;
    int     i;
    int     ret;

    if (n < 0 || p > n || p < 0)
        return (0);
    if (!(tab = (int*)malloc(sizeof(int) * (n + 1))))
        return (-1);
    for (i = 0; i <= n; i++)
        tab[i] = 1;
    for (i = 0; i < n; i++)
        binomiaux_bis_aux(tab, i);
    ret = tab[p];
    free(tab);
    return (ret);
}

void    recup_n_et_p(int *n, int *p)
{
    int     bon;

    bon = 0;
    printf("Inserer la valeur de n : ");
    do
    {
        if (bon)
            printf("Mauvaise valeur il faut que n soit positif : ");
        else
            bon = 1;
        scanf("%d", n);
    }while (*n < 0);
    bon = 0;
    printf("Inserer la valeur de p : ");
    do
    {
        if (bon)
            printf("Mauvaise valeur il faut que p soit positif et inférieur à n : ");
        else
            bon = 1;
        scanf("%d", p);
    }while (*p < 0 || *p > *n);
}

int     main(void)
{
    int     n;
    int     p;
    int     bin_rec;
    int     bin_ite;

    recup_n_et_p(&n, &p);
    if (!(bin_rec = binomiaux(n, p)))
        return (affiche_erreur(1));
    if ((bin_ite = binomiaux_bis(n, p)) <= 0)
        return (affiche_erreur(bin_ite + 1));
    printf("b_rec(%d,%d) = %d\nb_ite(%d,%d) = %d\n", n, p, bin_rec, n, p, bin_ite);
    return (0);
}
