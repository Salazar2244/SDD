#include <stdlib.h>
#include "hache.h"
#include <stdio.h>
#include <stdbool.h>

bool recherche_T_liste(T_liste,int);

tab_h init_tab_h(int n){
    tab_h table = (T_liste*) malloc(n*sizeof(T_liste)); //On reserve l'espace mémoire
    for(int i = 0; i<n; i++){
        table[i] = NULL; //Tout est null
    }
    return table;
}


void ajout_elt_tab_hache(tab_h table, int elt,int taille){
    int x = (elt % taille);
    ajout_entete_liste(&table[x],elt);
}
bool recherche_elt_tab_hache(tab_h table, int elt,int taille){
    int x = (elt % taille);
    bool b =recherche_T_liste(table[x],elt);
    return b;
}
void ajout_entete_liste(T_liste* pliste,int element){
    maillon* pnew = (maillon*) malloc(1*sizeof(maillon));
    pnew->val = element;
    pnew->lien = *pliste;
    *pliste = pnew;
}

bool recherche_T_liste(T_liste liste, int elt){
    if(liste->val == elt){
        printf("Trouvé!!\n");
        return true;        
    }
    else if(liste->lien == NULL){
        printf("Pas Trouvé :(\n");
        return false;
    }
    else{
        recherche_T_liste(liste->lien,elt);
    }
}
int main(){
    tab_h table = init_tab_h(9);
    ajout_elt_tab_hache(table,5,9);
    bool b = recherche_elt_tab_hache(table,6,9);
    free(table);
}