#ifndef MATRICE_H
#define MATRICE_H

#include <stdio.h>

typedef struct matrice {
    int lign;
    int col;
    char **elt;
} matrice;

matrice* matrice_create(int col, int lign);
void matrice_free(matrice* m);
void matrice_null(matrice* m);
void matrice_set(matrice* m, int i, int j, char x);
int matrice_get(const matrice* m, int i, int j);
void matrice_print(const matrice* m);
matrice* matrice_file(FILE* fp);
void matrice_save(const matrice* m, FILE* fp);

#endif
