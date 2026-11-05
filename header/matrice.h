#ifndef MATRICE_H
#define MATRICE_H
#include <stdio.h>
#include <stdlib.h>

typedef struct matrice_{ //definie la structure de données Matrice, pour gerer les coordonnées de la carte
    int lign;
    int col;
    char **elt;
} matrice;

matrice* matrice_create(int lign, int col);
void matrice_free(matrice * col);
void matrice_NULL(matrice* col);
void matrice_set(matrice* col, int i, int j, char x);
int matrice_get(matrice* col, int i, int j);
matrice* matrice_file(FILE* fp);
void matrice_save(matrice* m, FILE* fp);

#endif // MATRICE_H