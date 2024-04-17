#include"abr.h"
#include <stdbool.h>
#include<stdlib.h>
#include<stdio.h>
void afficher_bool(bool);


int main(){
    abr a = NULL;
    Ajout_feuille_rec(0,&a);
    bool b = recherche_abr_rec(a,0);
    afficher_bool(b);
    ajout_rota_rec(&a,5);
    printf("racine = %d\n",a->val);
    b = recherche_abr_rec(a,8);
    afficher_bool(b);
}
void afficher_bool(bool b){
    if(b == true){
        printf("true\n");
    }
    else{
        printf("false\n");
    }
}


void Ajout_feuille_rec(int x, abr * pa){
    abr tmp = (struct maillon *) malloc(sizeof(struct maillon));
    if( tmp != NULL){
        if((*pa) == NULL){
            tmp-> val = x;
            tmp->g = NULL;
            tmp->d = NULL;
            (*pa) = tmp;
        }
        else{
            if(tmp->val > x){
                Ajout_feuille_rec(x,&((*pa)->g));
            }
            else{
                Ajout_feuille_rec(x,&((*pa)->d));
            }
        }
    }
}

bool recherche_abr_rec(abr a,int x){
    if(a == NULL){
        return false;
    }
    else if(a->val == x){
        return true;
    }
    else if(a->val < x){
        return recherche_abr_rec(a->d,x);
    }
    else{
        return recherche_abr_rec(a->g,x);
    }
}
void rotation_g(abr * pa){
    abr temp = (*pa)->d;
    (*pa)->d = temp->g;
    temp->g = *pa;
    *pa = temp;
}
void rotation_d(abr * pa){
    abr temp = (*pa)->g;
    (*pa)->g = temp->d;
    temp->g = *pa;
    *pa = temp;
}

void ajout_rota_rec(abr * pa,int x){
    if((*pa) == NULL){
        Ajout_feuille_rec(x,pa);
    }
    else{
        if(x<(*pa)->val){
            ajout_rota_rec(&((*pa)->g),x);
            rotation_d(pa);
        }
        else{
            ajout_rota_rec(&((*pa)->d),x);
            rotation_g(pa);
        }
    }
}
