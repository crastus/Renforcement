#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>

typedef struct livre
{
    int id;
    char *titre;
    char *auteur;
    int nombre_ex;
    struct livre *next;
} livre_t;

livre_t *noeud(int id, char *titre, char *auteur, int nb)
{
    livre_t *list = malloc(sizeof(livre_t));

    if (list == NULL) {
        printf("Erreur de malloc");
        return NULL;
    }
    list->id = id;
    list->titre = titre;
    list->auteur = auteur;
    list->nombre_ex = nb;
    list->next = NULL;
    return list;
}

livre_t *add(livre_t **temp, int id, char *titre, char *auteur, int nb)
{
    livre_t *new = noeud(id, titre, auteur, nb);

    new->next = *temp;
    *temp = new;
    return *temp;
}

int main ()
{
    livre_t *mylist = NULL;
    livre_t *jeu;
    add(&mylist, 1, "Le premier", "Zozo de zozo", 2);
    add(&mylist, 2, "Le deuxieme", "Zazo de zazo", 3);
    add(&mylist, 2, "Le troisieme", "Zouzi de zouzi", 4);
    jeu = mylist;
    while (jeu != NULL) {
        printf("%s \n", jeu->titre);
        jeu = jeu->next;
    }
    return 0;
}
