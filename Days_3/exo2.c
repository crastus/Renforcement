#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>

//Cette fonction affiche les nombres divisibles par 3 mais non divisible par 5
/*Encore une fois beacoup de lignes de code inutiles. Tu peux vérifier deux conditions simultanément. Et puis tu peux commencer directement par 3.*/
void exo2(int nbr)
{
    int n = 1;

    while (n <= nbr) {
        if (n % 3 == 0) {
            if (n % 5 == 0) {
                n++;
            } else {
                printf("%d \n", n);
            }
        }
        n++;
    }
}
