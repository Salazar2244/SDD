#include"stdbool.h"
struct maillon {int val; struct maillon * g ; struct maillon * d;};
typedef struct maillon* abr;
//On a défini le type ABR

void Ajout_feuille_rec(int, abr*);
bool recherche_abr_rec(abr,int);
void rotation_d(abr *);
void rotation_g(abr *);
void ajout_rota_rec(abr*,int);