#ifndef SERPENT_H
#define SERPENT_H
#include <stdbool.h>
#include "matrice.h"

typedef struct Cellule {
    char lettre;
    int x; //position x sur la map
    int y; //position y sur la map
    struct Cellule* suiv;
} Cellule, *Serpent;

Serpent initialiser_serpent(int x_depart, int y_depart);
bool grandir_serpent(Serpent* tete, char nouvelle_lettre, int nouveau_x, int nouveau_y);
int verifier_collision(Serpent tete, int nouv_x, int nouv_y, const matrice* carte);
int calculer_taille(Serpent tete);
void liberer_serpent(Serpent* tete);

#endif // SERPENT_H