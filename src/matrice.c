#include "../header/matrice.h"
#include <stdio.h>
#include <stdlib.h>

matrice* matrice_create(int col, int lign){
    int i;
    matrice* r = (matrice *) malloc(sizeof(matrice));
    r->lign = lign;
    r->col = col;
    r->elt = (char **) malloc((lign * col) * sizeof(char));
    for(i = 0; i < lign; i++){
        r->elt[i] = (char*) malloc(sizeof(char));
    }
    return r;
}

void matrice_free(matrice* r){
    int i;
    for(i = 0; i < r->lign; i++){
        free(r->elt[i]);
    }
    free(r->elt);
    free(r);
}

void matrice_null(matrice* r){
    int i, j;
    for(i = 0; i < r->lign; i++){
        for(j = 0; j < r->col; j++){
            r->elt[i][j] = 0;
        }
    }
}

void matrice_set(matrice* m, int i, int j, char x){ //fonction pour modifier une valeur, i = ligne, j = colonne
    if(i > m ->lign && j < m->col){
        m->elt[i][j] = x;
    }
}

void matrice_print(matrice* m){
    int i, j;
    for(i = 0; i < m->lign; i++){
        for(j = 0; j < m->col; j++){
            printf("%c ", m->elt[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

matrice* matrice_file(FILE* fp){
    int i, j, n, m;
    fscanf(fp, "%d", &n);
    fscanf(fp, "%d", &m);
    matrice* r = matrice_create(m, n);
    for(i = 0; i < r->lign; i++){
        for(j = 0; j < r->col; j++){
            fscanf(fp, "%c", &r->elt[i][j]);
        }
    }
    return r;
}

void matrice_save(matrice* m, FILE* fp){
    int i, j;
    fprintf(fp, "%d %d\n", m->lign, m->col);
    for(i = 0; i < m->lign; i++){
        for(j = 0; j < m->col; j++){
            fprintf(fp, "%c ", m->elt[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}