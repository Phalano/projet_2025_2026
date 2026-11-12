#include <stdio.h>
#include "../header/matrice.h"

int main(void){
    FILE* fp = fopen("../sauvegarde/carte.txt", "w+");
    matrice* m = matrice_create(5, 7);
    matrice_null(m);
    matrice_save(m, fp);
    matrice_print(m);
    return 1;
}