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
/*ah bon? quel professeur t'a appris a déterminer un nombre premier ainsi?*/
void n_premier(int nbr)
{
    int i = 1;
    int pts = 0;

    if (nbr < 10) {
        for (int i = 0; i < nbr; i++) {
            m_putstr("bonjour\n");
        }
    } else {
        while (i <= nbr) {
            if (nbr % i == 0)
                pts++;
            i++;
        }
        if (pts == 2) {
            m_putstr("C'est un nombre premier\n");
        } else {
            m_putstr("C'est pas un nombre premier\n");
        }
    }

}
