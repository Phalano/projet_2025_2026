#include "../header/matrice.h"
#include <stdio.h>
#include <stdlib.h>

matrice* matrice_create(int col, int lign)
{
    int i;
    matrice* r;

    if (col <= 0 || lign <= 0) {
        return NULL;
    }

    r = malloc(sizeof(matrice));
    if (r == NULL) {
        return NULL;
    }
    r->lign = lign;
    r->col = col;

    r->elt = malloc((size_t)lign * sizeof(char*));
    if (r->elt == NULL) {
        free(r);
        return NULL;
    }

    for (i = 0; i < lign; i++) {
        r->elt[i] = malloc((size_t)col * sizeof(char));

        if (r->elt[i] == NULL) {
            while (i > 0) {
                free(r->elt[--i]);
            }
            free(r->elt);
            free(r);
            return NULL;
        }
    }
    return r;
}

void matrice_free(matrice* r)
{
    int i;
    if (r == NULL) {
        return;
    }

    for (i = 0; i < r->lign; i++) {
        free(r->elt[i]);
    }
    free(r->elt);
    free(r);
}

void matrice_null(matrice* r)
{
    int i, j;
    if (r == NULL) {
        return;
    }

    for (i = 0; i < r->lign; i++) {
        for (j = 0; j < r->col; j++) {
            r->elt[i][j] = '0';
        }
    }
}

void matrice_set(matrice* m, int i, int j, char x)
{
    if (m == NULL) {
        return;
    }

    if (i >= 0 && i < m->lign &&
        j >= 0 && j < m->col) {
        m->elt[i][j] = x;
    }
}

void matrice_print(matrice* m)
{
    int i, j;
    if (m == NULL) {
        return;
    }

    for (i = 0; i < m->lign; i++) {
        for (j = 0; j < m->col; j++) {
            printf("%c ", m->elt[i][j]);
        }
        printf("\n");
    }
}

matrice* matrice_file(FILE* fp)
{
    int i, j, n, m;
    matrice* r;

    if (fp == NULL) {
        return NULL;
    }

    if (fscanf(fp, "%d %d", &n, &m) != 2) {
        return NULL;
    }

    r = matrice_create(m, n);
    if (r == NULL) {
        return NULL;
    }

    for (i = 0; i < r->lign; i++) {
        for (j = 0; j < r->col; j++) {
            if (fscanf(fp, " %c", &r->elt[i][j]) != 1) {
                matrice_free(r);
                return NULL;
            }
        }
    }
    return r;
}

void matrice_save(matrice* m, FILE* fp)
{
    int i, j;
    if (m == NULL || fp == NULL) {
        return;
    }
    fprintf(fp, "%d %d\n", m->lign, m->col);

    for (i = 0; i < m->lign; i++) {
        for (j = 0; j < m->col; j++) {
            fprintf(fp, "%c ", m->elt[i][j]);
        }
        fprintf(fp, "\n");
    }
}
