#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>

/*Exercice correct*/

//Cette fonction sert a affiché un seul caractère
char m_putchar (char a)
{
    write(1, &a, 1);
}

//Cette fonction sert a affiché un ensemble de caractère (ex: "moto")
int m_putstr (char *a)
{
    int i = 0;
    for (i = 0; a[i] != '\0'; i++) {
        m_putchar(a[i]);
    }
    return 0;
}

//cette fonction convertir une chaine de caractere en entier
int m_getnbr(char const *str)
{
    int i = 0;
    int n = 1;
    int j = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            j = j * 10;
            j = j + str[i] - '0';
        } else {
            return 0;
        }
        if (str[i] == '-') {
            n = n * -1;
        }
    }
    return j * n;
}

//Cette fonction sert a vérifié si vous etes mineur ou majeur
//Elle prends en parametre un entier qui sera votre age
void Mimaj (int age)
{
    if (age > 17) {
        m_putstr("Majeur\n");
    } else {
        m_putstr("Mineur\n");
    }
}

int main ()
{
    int nbr;
    m_putstr("Entrez votre age : \n");
    scanf("%d", &nbr);   
    Mimaj(nbr);
}

//Note : 05/10
//Ici, je voulais que tu demandes a l'utilisateur son age et que tu le récupères et non qu'il passe ca en ligne de commande