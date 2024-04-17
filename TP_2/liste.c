/* ==================================== Include    =================================== */
#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

/* ==================================== Functions and procedures =================================== */

int main(){
    T_liste liste = creer_liste();
    T_liste liste_inverser;
    ajout_entete_liste(&liste,1);
    ajout_entete_liste(&liste,2);
    ajout_entete_liste(&liste,3);
    fafficher_dir_liste(liste);
    fafficher_inv_liste(liste);
    inv_mis_liste(&liste);
    printf("\n");
    fafficher_inv_liste(liste);
    liste_inverser = inv_fonc_liste(liste);
    fafficher_dir_liste(liste_inverser);
    return 0;
}
T_liste creer_liste(){
    T_liste liste = NULL;
    return liste;
}
void ajout_entete_liste(T_liste* pliste,int element){
    maillon* pnew = (maillon*) malloc(1*sizeof(maillon));
    pnew->val = element;
    pnew->lien = *pliste;
    *pliste = pnew;
}


void fafficher_inv_liste(T_liste liste){
    if(liste->lien == NULL){
        printf("%d ",liste->val);    }
    else{
        fafficher_inv_liste(liste->lien);
        printf("%d ",liste->val);
    }
}

void inv_mis_liste(T_liste * pliste){
    T_liste inv,n_inv,tmp;
    inv = NULL;
    n_inv = *pliste;
    while(n_inv!=NULL){
        tmp = (*n_inv).lien;
        (*n_inv).lien = inv;
        inv = n_inv;
        n_inv =tmp;
    }
    *pliste = inv;
}
T_liste inv_fonc_liste(T_liste liste){
    T_liste copie_liste;
    while(liste->lien !=NULL){
        ajout_entete_liste(&copie_liste,liste->val);
    }
    ajout_entete_liste(&copie_liste,liste->val);
    return copie_liste;
}