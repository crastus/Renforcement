#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>

char *romain(int year)
{
    char *rom[] = {"M", "D", "C", "L", "X", "V", "I"};
    int annee[] = {1000, 500, 100, 50, 10, 5, 1};

    for (int i = 0; i < 7; i++) {
        while (year >= annee[i]) {
            printf("%s", rom[i]);
            year = year - annee[i];
        }
    }
    printf("\n");
}

int main (int ac, char **av)
{
    romain(atoi(av[1]));
    return 0;
}