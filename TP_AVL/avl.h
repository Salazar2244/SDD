/* En-tete de arbre
   ----------------
   objectif : définir le TAA arbre */

#ifndef AVL_H
#define AVL_H
#define max 20
/* type noeud incomplet */
typedef struct s_node T_node;
/* type pointeur sur noeud */
typedef T_node * T_Tree;
/* type noeud complet */
struct s_node {
    int val;
    T_Tree g,d;
    int eq; // dans -1 0 1
};


T_Tree arbre_vide();
void insertion_feuille(T_Tree * T, int i);
bool recherche(T_Tree T, int i);
void lecture_arbre(T_Tree T);
#endif