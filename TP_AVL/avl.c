#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "avl.h"

T_Tree init_Tree()
{
    return NULL;
}

T_Tree creer_noeud(int i)
{
    T_Tree t = (T_node *)malloc(sizeof(T_node));
    if (t != NULL)
    {
        t->val = i;
        t->g = NULL;
        t->d = NULL;
    }
    else
    {
        printf("pbm allocation memoire!\n");
    }
    return t;
}

void lecture_arbre(T_Tree T)
{
    if (T != NULL)
    {
        printf("< ");
        lecture_arbre(T->g);
        printf(" , %d , ", T->val);
        lecture_arbre(T->d);
        printf(">\n");
    }
    else
    {
        printf("<> ");
    }
}

void rotation_g(T_Tree *pT)
{
    // precondition : arbre de hauteur 1 avec son sous-arbre droit non vide
    if (((*pT)->d) == NULL)
    {
        printf("Erreur");
        exit(EXIT_FAILURE);
    }
    else
    {
        // On effetcue la rotatio car la pre-condition est remplie
        T_Tree temp = (*pT)->d;
        // Mettre à jour les degrés
        (*pT)->g->eq = (*pT)->g->eq + 1;
        (*pT)->d->eq = (*pT)->d->eq - 1;
        (*pT)->d = temp->g;
        temp->g = *pT;
        *pT = temp;
        printf("Travail terminé\n");
        exit(EXIT_SUCCESS);
    }
}

void rotation_d(T_Tree *pT)
{
    if (((*pT)->g) == NULL)
    {
        printf("Erreur");
        exit(EXIT_FAILURE);
    }
    else
    {
        // On effetcue la rotatio car la pre-condition est remplie
        T_Tree temp = (*pT)->g;
        // Mettre à jour les degrés
        (*pT)->d->eq = (*pT)->d->eq + 1;
        (*pT)->g->eq = (*pT)->g->eq - 1;
        (*pT)->g = temp->d;
        temp->d = *pT;
        *pT = temp;
        printf("Travail terminé\n");
        exit(EXIT_SUCCESS);
    }
}

void rotation_g_d(T_Tree *pT)
{
    // precondition : arbre de hauteur 2 avec son sous-arbre gauche puis sous sous-droit non vide
    if (((*pT)->g) != NULL)
    {
        if (((*pT)->g)->d == NULL)
        {
            printf("Erreur");
            exit(EXIT_FAILURE);
        }
        else
        {
            rotation_g(&((*pT)->g));
            rotation_d(pT);
        }
    }
    // precondition : arbre de hauteur 2 avec son sous-arbre droit puis gauche non vide
}

void rotation_d_g(T_Tree *pT)
{
    // precondition : arbre de hauteur 2 avec son sous-arbre gauche puis sous sous-droit non vide
    if (((*pT)->d) != NULL)
    {
        if (((*pT)->d)->g == NULL)
        {
            printf("Erreur");
            exit(EXIT_FAILURE);
        }
        else
        {
            rotation_d(&((*pT)->d));
            rotation_g(pT);
        }
    }
    // switch (gtmp->eq)
    // {

    // case 1:
    //     dtmp->eq = -1;
    //     (*T)->eq = 0;
    //     break;
    // case -1:
    //     dtmp->eq = 0;
    //     (*T)->eq = 1;
    //     break;
    // case 0:
    //     dtmp->eq = 0;
    //     (*T)->eq = 0;
    //     break;
    // }
    // // mise a jour du degre de la future racine
    // gtmp->eq = 0;
    // // mise a jour de l'arbre *T
    // (*T) = gtmp;
}

void insertion(T_Tree *T, int i, int *h)
{
    printf("Prout\n");
    if (*T == NULL)
    { // cas de base
        (*T) = creer_noeud(i);
        if (*T == NULL)
        {
            printf("Allocation familial impossible\n");
            (*h) = 0;
        }
        else
        {
            (*h) = 1;
        }
    }
    else
    { // HR : on sait inserer un element dans un arbre de hauteur plus petite
        if (i < ((*T)->val))
        {   printf("COulante\n");
            insertion(&((*T)->g), i, h);
            if (*h == 1)
            {
                switch (((*T)->eq))
                {
                case -1:
                    ((*T)->eq) = 0;
                    *h = 0;
                    break;
                case 0:
                    ((*T)->eq) = 1;
                    *h = 1;
                    break;
                case 1:
                    if ((((*T)->g)->eq) == 1)
                    {
                        // rotation simple vers la droite
                        rotation_d(T);
                    }
                    else
                    {
                        // rotation double
                        rotation_g_d(T);
                    }
                    *h = 0;
                    break;
                }
            }
        }
        else
        {
            // completer le cas d'insertion dans le sous-arbre droit
            printf("caca\n");
            insertion(&((*T)->d), i, h);
            if (*h == 1)
            {
                switch (((*T)->eq))
                {
                case -1:
                    ((*T)->eq) = 0;
                    *h = 0;
                    break;
                case 0:
                    ((*T)->eq) = 1;
                    *h = 1;
                    break;
                case 1:
                    if ((((*T)->d)->eq) == 1)
                    {
                        // rotation simple vers la droite
                        rotation_g(T);
                    }
                    else
                    {
                        // rotation double
                        rotation_d_g(T);
                    }
                    *h = 0;
                    break;
                }
            }

        }
    }
}

void insertion_feuille(T_Tree *T, int i)
{
    int h = 0;
    insertion(T, i, &h);
}

int main()
{
    T_Tree a; // b;

    a = init_Tree();
    // b = init_Tree();
    // insertion_feuille(&a, 10);
    Printf("Essaie1\n");
    insertion_feuille(&a, 2);
    insertion_feuille(&a, 4);
    insertion_feuille(&a, 8);
    lecture_arbre(a);
    // bool b = recherche(a, 10);
    // if (b == false)
    // {
    //     printf("Non\n");
    // }
    // else
    // {
    //     printf("Oui\n");
    // }
    return 0;
}
