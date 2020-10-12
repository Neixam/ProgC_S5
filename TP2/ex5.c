/* Auteur       : Bourennane Amine
*  Creation     : 12-10-2020
*  Modification : 12-10-2020   */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char    c1;
    int     i1;
    char    c2;
    int     i2;
}Test1;

typedef struct {
    char    c1;
    char    c2;
    int     i1;
    int     i2;
}Test2;

char    glob = 'o';
static char   stat = 'z';

int     main(void)
{
    char    loc1 = 'v';
    char    loc2 = 'q';
    char    *all1;
    char    *all2;
    Test1   t1;
    Test2   t2;

    if (!(all1 = (char*)malloc(sizeof(char) * 103)))
        return (1);
    if (!(all2 = (char*)malloc(sizeof(char) * 103)))
        return (1);
    printf("static <--> globale : %ld\n", &stat - &glob);
    printf("static <--> locale1 : %ld\n", &stat - &loc1);
    printf("static <--> locale2 : %ld\n", &stat - &loc2);
    printf("static <--> allouée1 : %ld\n", &stat - all1);
    printf("static <--> allouée2 : %ld\n", &stat - all2);
    printf("globale <--> locale1 : %ld\n", &glob - &loc1);
    printf("globale <--> locale2 : %ld\n", &glob - &loc2);
    printf("globale <--> allouée1 : %ld\n", &glob - all1);
    printf("globale <--> allouée2 : %ld\n", &glob - all2);
    printf("locale1 <--> allouée1 : %ld\n", &loc1 - all1);
    printf("locale1 <--> allouée2 : %ld\n", &loc1 - all2);
    printf("locale1 <--> locale2 : %ld\n", &loc1 - &loc2);
    printf("allouée1 <--> allouée2 : %ld\n", all1 - all2);
    printf("Test1 %ld Test2 %ld\n", sizeof(t1), sizeof(t2));
    return (0);
}
