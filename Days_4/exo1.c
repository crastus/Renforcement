#include <stdio.h>
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

// Iterative function to delete a linked list
void deleteNode(livre_t* head)
{
    free(head->titre),
    free(head->auteur);
    free(head);
	//livre_t *temp = *head;
    //(*head) = (*head)->next;
    //free(temp);
}

void deleteNodeInList(livre_t **list, livre_t *node)
{
    if (list == NULL) {
        return;
    }
    if (*list == node) {
        (*list) = (*list)->next;
        free(node);
        return;
    }
    livre_t *temp1 = node;
    livre_t *prec = NULL;
    while ((*list)->next != NULL) {
        if (*list != node) {
            temp1 = temp1->next;
            free(temp1);
            return;
        }
        prec = (*list);
        (*list) = (*list)->next;
    }
    /*livre_t *current = *list;
    livre_t *prec = NULL;
    while (current->next != NULL)
    {
        current = current->next;
        free(current);
        (*list)->next = NULL;
    }  */  
}
void zamb(livre_t **list, livre_t *node)
{
    livre_t *temp1 = node;
    livre_t *prec = NULL;
    while ((*list)->next != NULL) {
        if (*list != node) {
            *list = temp1->next;
            free(temp1);
            return;
        }
        prec = (*list);
        (*list) = (*list)->next;
    }
}

void affichage (livre_t *list)
{
    livre_t *jeu = list;
    while (jeu != NULL) {
        printf("%s \n", jeu->titre);
        jeu = jeu->next;
    }
}
livre_t *trie(livre_t **list, char *nom)
{
    while (*list != NULL) {
        if ((*list)->titre == nom || (*list)->auteur == nom) {
            affichage(*list);
            return *list;
        }
        *list = (*list)->next;
    }
    return NULL;
}

int main (int ac, char **av)
{
    livre_t *mylist = NULL;
    if (av[1] = "add") {
        add(&mylist, atoi(av[2]), av[3], av[4], atoi(av[5]));
    }
    if (av[1] = "supp") {
        
    }
}
/*int main ()
{
    livre_t *mylist = NULL;
    add(&mylist, 1, "Le premier", "Zozo de zozo", 2);
    add(&mylist, 2, "Le deuxieme", "Zazo de zazo", 3);
    add(&mylist, 2, "Le troisieme", "Zouzi de zouzi", 4);
    affichage(mylist);
    zamb(&mylist, mylist->auteur);
    affichage(mylist);
    return 0;
}*/