#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>

//Cette fonction affiche les nombres divisibles par 3 mais non divisible par 5
/*Encore une fois beacoup de lignes de code inutiles. Tu peux vérifier deux conditions simultanément. Et puis tu peux commencer directement par 3.*/
void exo2(int nbr)
{
    int n = 1;
    int n1 = 0;

    while (n <= nbr) {
        n1 = n % 3;
        if (n1 == 0) {
            n1 = n % 5;
            if (n1 == 0) {
                n++;
            } else {
                printf("%d \n", n);
            }
        } else {
            n++;
        }
        n++;
    }
}