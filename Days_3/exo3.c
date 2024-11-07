#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>

char m_putchar (char a)
{
    write(1, &a, 1);
    /*correct je comprend*/
}

int m_putstr (char *a)
{
    int i = 0;
    for (i = 0; a[i] != '\0'; i++) {
        m_putchar(a[i]);
    }
    return 0;
}

//Cette fonction vous dis si le nombre que vous entrez est un nombre premier ou pas.
//Cependant, si le nombre entrez est inférieur a 10, il affiche bonjour * le nombre entrez
void n_premier(int nbr)
{
    int n = nbr % 3;
    int n1 = nbr % 2;
    if (nbr < 10) {
        for (int i = 0; i < nbr; i++) {
            m_putstr("bonjour\n");
        }
    } else {
        if (n != 0 && n1 != 0) {
            m_putstr("C'est un nombre premier\n");
        } else {
            m_putstr("C'est pas un nombre premier\n");
        }
    }
}

int main(int ac, char **av)
{
    n_premier(atoi(av[1]));
}
