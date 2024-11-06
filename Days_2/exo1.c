#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

//Cette fonction sert a affiché un seul caractère
char m_putchar (char a)
{
    write(1, &a, 1);
    /*correct je comprend*/
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

    /* ah bon? tu retournes 0 et tu me parles de chaine de caractères?*/

    return 0;
}

/*fonction inutile. Tu n'as pas respecté la consigne. J'ai dis qu'ici, on attend pas un input de l'utilisateur. On appelle directement la fonction avec les paramètres*/

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

/* Tu n'as rien compris de l'exercice. La fonction prend en paramètre l'année et non le nombre de jours. C'est a toi meme de vérifier certaines conditions sur l'année pour savoir si elle est bissextile ou non*/

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

/*Aucune fonction main n'est attendue dans cet exercice je voulais juste la fonction qui renvoie True ou False en fonction de l'année. Et a la limite si tu veux faire de fonction main, tu appelles ta fonction avec un paramètre bien défini. Ici, on ne prend pas l'input a partir du terminal*/

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

/* Note pour l'exercice : 01 / 10*/
/*Pour t'aider un peu*/
/* Une année est dite bissextile si c'est un multiple de 4, sauf si c'est un multiple de 100. Toutefois, elle est considérée comme
bissextile si c'est un multiple de 400. Je développe :
Si une année n'est pas multiple de 4, on s'arrête là, elle n'est pas bissextile.
Si elle est multiple de 4, on regarde si elle est multiple de 100.
    Si c'est le cas, on regarde si elle est multiple de 400.
        Si c'est le cas, l'année est bissextile.
        Sinon, elle n'est pas bissextile.
    Sinon, elle est bissextile.*/