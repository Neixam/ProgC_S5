/**
 *  Auteur       : Bourennane Amine
 *  Creation     : 22-11-2020
 *  Modification : 23-11-2020
**/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "code.h"

/**
 *  Range une clé aléatoire dans l'adresse de `B`
**/
int     cle_alea(Bitkey *B)
{
    int     i;

    for (i = 0; i < NB_OCT; i++)
        B->values[i] = rand() % 256; /* random uint8_t */
    return (0);
}

/**
 *  Fonction de comparaison pour qsort entre 2 Bitkey
**/
int     bitkcmp(const void *a, const void *b)
{
    Bitkey  *k1;
    Bitkey  *k2;

    k1 = (Bitkey*)a;
    k2 = (Bitkey*)b;
    /* comparaison des fitness */
    return ((int)(fitness_key(k2) - fitness_key(k1)));
}

/**
 *  Fait l'accouplement des 3 clés `k1`, `k2` et `k3` dans l'adresse de la clé
 *  `B` 
**/
void    accouplement(Bitkey *B, Bitkey k1, Bitkey k2, Bitkey k3)
{
    int     i;

    for (i = 0; i < NB_OCT; i++)
        B->values[i] = (k1.values[i] & k2.values[i]) | /* P1 et P2 ou */
                       (k1.values[i] & k3.values[i]) | /* P1 et P3 ou */
                       (k2.values[i] & k3.values[i]);  /* P2 et P3 */
}

/**
 *  Génère une clé dans l'adresse Bitkey `B` de génération `d`
**/
int     generate_cle_generation(Bitkey *B, int d)
{
    Bitkey  *tab;
    int     i;

    if (d <= 0)
        return (cle_alea(B)); /* retourne une clé aléatoire dans B */
    /* allocation d’un tableau de 8 clés */
    if (!(tab = (Bitkey *) malloc(sizeof(Bitkey) * 8)))
        return (1);
    /* génération de 8 clé de génération d-1 8 appels récursifs */
    for (i = 0; i < 8; i++)
    {
        if (generate_cle_generation(&tab[i], d - 1))
        {
            free(tab);
            return (1);
        }
    }
    /* tri du tableau */
    qsort(tab, 8, sizeof(Bitkey), bitkcmp);
    /* accouplement des 3 meilleurs clés et fabrication de l’enfant dans B */
    accouplement(B, tab[0], tab[1], tab[2]);
    /* libération mémoire du tableau */
    free(tab);
    return (0);
}

int     main(void)
{
    Bitkey  B;
    int     i;

    srand(time(NULL));
    i = 0;
    do
    {
        printf("generation %d\n", i);
        if (generate_cle_generation(&B, i))
            return (1);
        printf("sucess %2.2f%%\n", fitness_key(&B));
        enter_the_matrix(&B);
        i++;
    } while (fitness_key(&B) < 100);
    return (0);
}
