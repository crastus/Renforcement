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
//La fonction prends en paramètre une chaine de caractere
int m_putstr (char *a)
{
    int i = 0;
    for (i = 0; a[i] != '\0'; i++) {
        m_putchar(a[i]);
    }
    /* ah bon? tu retournes 0 et tu me parles de chaine de caractères?*/
    return 0;
}

/*fonction inutile. Tu n'as pas respecté la consigne. J'ai dis qu'ici, on attend pas un input de l'utilisateur. On appelle directement la fonction avec les paramètres*/

/* Tu n'as rien compris de l'exercice. La fonction prend en paramètre l'année et non le nombre de jours. C'est a toi meme de vérifier certaines conditions sur l'année pour savoir si elle est bissextile ou non*/

//Cette fonction retourne "True" si l'année est bissextile et "False" si elle ne l'est pas
/* La fonction est correcte mais on peut faire mieux. Il y a beaucoup de lignes inutiles dont on peut se passer. Déja, l'utilisation de la variable nbr est inutile. Tu peux comparer directement dans la condition if. Ensuite tu peux vérifier directement les trois conditions simultanément*/
/*Un apercu de ce que je dis*/

char *bissextile_or_not(int year)
{
    if ((year % 4 == 0) && ((year % 100 != 0 || year % 400 == 0)))
        return ("True");
    return ("False");
}

char *fonction_bs(int year)
{
    if (year % 4 == 0) {
        if (year % 100 != 0 || year % 400 == 0)
            return ("True\n");
    }
    return ("false\n");
}

/*Aucune fonction main n'est attendue dans cet exercice je voulais juste la fonction qui renvoie True ou False en fonction de l'année. Et a la limite si tu veux faire de fonction main, tu appelles ta fonction avec un paramètre bien défini. Ici, on ne prend pas l'input a partir du terminal*/

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