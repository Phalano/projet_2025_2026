#ifndef TAILLE_SERPENT_H
#define TAILLE_SERPENT_H
#include <stdbool.h>

typedef struct Cellule{
    char lettre;
    int x;  //position x sur la map
    int y;  //position y sur la map
    struct Cellule* suiv;
} Cellule, *Serpent;

Serpent initialiser_serpent(int x_depart, int y_depart);
void grandir_serpent(Serpent* tete, char nouvelle_lettre, int nouveau_x, int nouveau_y);
int calculer_taille(Serpent tete);
void liberer_serpent(Serpent tete);

#endif // TAILLE_SERPENT_H