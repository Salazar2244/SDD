/* En-tete de liste
   ----------------
   objectif : définir le TAA liste */
   
#ifndef _Liste_h
#define _Liste_h

// définir le type T_liste (typedef ...)
struct maillon_t {int val; struct maillon_t * lien;};
typedef struct maillon_t maillon;
typedef maillon* T_liste;
    
// prototypes des méthodes

// creation liste vide
T_liste creer_liste();
// ajout en tete de liste de element avec modification de la liste
void ajout_entete_liste(T_liste *, int);
// ajout en tete selon une approche fonctionnelle sans modification de la liste
//T_liste ajouter_entete_fonc(..., int element);

// affichages
// itératif
//void afficher_liste(...);
// récursif dans l ordre de la liste
void fafficher_dir_liste(T_liste);
// récursif dans l ordre inverse de la liste
void fafficher_inv_liste(T_liste);



// inversion iterative d'une liste selon une approche MIS
void inv_mis_liste(T_liste*);
// inversion iterative d'une liste selon une approche fonctionnelle
T_liste inv_fonc_liste(T_liste);

// comptage du nombre d'elements d'une liste
// selon une approche recursive enveloppee
//int long_env(T_liste liste)
// selon une approche recursive terminale
//int long_ter(T_liste liste, int aux);

// inversion recursive enveloppee d'une liste
//T_liste inversion_rec_env(?);
// inversion recursive terminale d'une liste
//T_liste inversion_rec_term(?);

// liberation de la mémoire
//void liberer_liste(?);
#endif
