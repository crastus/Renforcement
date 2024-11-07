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

//Cette fonction permet de de faire la différence entre entre un nombre PAIR et IMPAIR
void pair_impair(int nbr)
{
    int n = nbr % 2;

    if (n == 0) {
        m_putstr("PAIR\n");
    } else {
        m_putstr("IMPAIR\n");
    }
}

//Cette fonction fait la meme chose que la premiere a la difference que j'ai utilisé les ternaires
void pair_impair2(int nbr)
{
    int n = nbr % 2;

    n == 0 ? m_putstr("PAIR\n") : m_putstr("IMPAIR\n");
}
