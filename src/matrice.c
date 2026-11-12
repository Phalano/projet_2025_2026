#include "../header/matrice.h"
#include <stdlib.h>

matrice* matrice_create(int col, int lign)
{
    int i;
    matrice* m;

    if (col <= 0 || lign <= 0) {
        return NULL;
    }

    m = malloc(sizeof *m);
    if (m == NULL) {
        return NULL;
    }
    m->lign = lign;
    m->col = col;

    m->elt = malloc((size_t)lign * sizeof *m->elt);
    if (m->elt == NULL) {
        free(m);
        return NULL;
    }

    for (i = 0; i < lign; i++) {
        m->elt[i] = malloc((size_t)col * sizeof *m->elt[i]);
        if (m->elt[i] == NULL) {
            while (i > 0) {
                free(m->elt[--i]);
            }
            free(m->elt);
            free(m);
            return NULL;
        }
    }
    return m;
}

void matrice_free(matrice* m)
{
    int i;
    if (m == NULL) {
        return;
    }

    for (i = 0; i < m->lign; i++) {
        free(m->elt[i]);
    }
    free(m->elt);
    free(m);
}

void matrice_null(matrice* m)
{
    int i, j;
    if (m == NULL) {
        return;
    }

    for (i = 0; i < m->lign; i++) {
        for (j = 0; j < m->col; j++) {
            m->elt[i][j] = '0';
        }
    }
}

void matrice_set(matrice* m, int i, int j, char x)
{
    if (m != NULL && m->elt != NULL &&
        i >= 0 && i < m->lign && j >= 0 && j < m->col &&
        m->elt[i] != NULL) {
        m->elt[i][j] = x;
    }
}

int matrice_get(const matrice* m, int i, int j)
{
    if (m == NULL || m->elt == NULL ||
        i < 0 || i >= m->lign || j < 0 || j >= m->col ||
        m->elt[i] == NULL) {
        return EOF;
    }
    return (unsigned char)m->elt[i][j];
}

void matrice_print(const matrice* m)
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
    int i, j, lign, col;
    matrice* m;

    if (fp == NULL || fscanf(fp, "%d %d", &lign, &col) != 2) {
        return NULL;
    }

    m = matrice_create(col, lign);
    if (m == NULL) {
        return NULL;
    }

    for (i = 0; i < m->lign; i++) {
        for (j = 0; j < m->col; j++) {
            if (fscanf(fp, " %c", &m->elt[i][j]) != 1) {
                matrice_free(m);
                return NULL;
            }
        }
    }
    return m;
}

void matrice_save(const matrice* m, FILE* fp)
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
