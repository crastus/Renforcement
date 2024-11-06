#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

//Cette fonction sert a affiché un seul caractère
char m_putchar (char a)
{
    write(1, &a, 1);
}

//Cette fonction sert a affiché un ensemble de caractère (ex: "moto")
//La fonction prends en paramètre une chaine de caractere et retorune une chaine de caractere
int m_putstr (char *a)
{
    //Nous déclarons un compteur i afin de parcourir la chaine
    int i = 0;
    //Ici nous avons la boucle qui parcours la chaine de caractere
    for (i = 0; a[i] != '\0'; i++) {
        //ici, m_putchar affiche chaque caractere de la chaine de caractere
        //tout en s'incrémentant d'ou l'utilité du compteur
        m_putchar(a[i]);
    }
    //ici on retourne la chaine de caractere
    return 0;
}

//cette fonction convertir une chaine de caractere en entier
int m_getnbr(char const *str)
{
    //declaration de pointeur
    int i = 0;
    //declaration d'un entier intialisé a 1 pour les nombres négatifs
    int n = 1;
    //declaration d'entier ou la conversion se passera
    int j = 0;
    //On parcours la chaine de caractere
    for (i = 0; str[i] != '\0'; i++) {
        //On verifie si les caracteres sont des nombres, si oui
        if (str[i] >= '0' && str[i] <= '9') {
            j = j * 10;
            j = j + str[i] - '0';
        //dans le cas contraire retourne 0
        } else {
            return 0;
        }
        //ici on vérifie si la chaine de caractere est un nombre négatif
        if (str[i] == '-') {
            //alors on multiplie par -1
            n = n * -1;
        }
    }
    return j * n;
}

//Cette fonction retourne "True" ou "False" en fonction de l'année
char *fonction_bs(int nbr)
{
    //On a posé des conditions donc si l'année comporte 366njours
    //elle est bissestile
    if (nbr == 366) {
        return ("True\n");
    // et si l'année comporte 365 jours, elle est non bissestile
    } else if (nbr == 365) {
        return ("false\n");
    //et si elle ne respecte aucune de ses condition elle affiche un message
    } else {
        return ("Aucune année ne comporte plus de 366 jours et moins de 365 jours\n");
    }
}

//La fonction principale
//elle a pris en parametre "int ac, et char **av"
//parce qu'on a besoin des informations entrée depuis le terminale
//en d'autres termes les arguemnts
//int ac stocke le nombre d'argument et char **av stocke l'argument lui meme
int main (int ac, char **av)
{
    //Je vérifie si le nombre d'argument ne depasse pas 2 ou est plus petit que 2
    if (ac != 2) {
        return 0;
    }
    //Ici je rappelle ma fonction bissestile tout en convertissant l'argument (chaine de caractere) en entier
    //qui est stocke dans la chaine de caractere bof le message "true" ou "false"
    char *bof = fonction_bs(m_getnbr(av[1]));
    //j'affiche
    m_putstr(bof);
}