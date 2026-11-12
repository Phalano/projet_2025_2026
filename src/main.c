#include <stdio.h>
#include <stdlib.h>
#include "serpent.h"


int main(){
    Serpent tete = initialiser_serpent(10, 10);
    if (tete == NULL){
        return EXIT_FAILURE;
    }

    if (!grandir_serpent(&tete, 'A', 11, 10) ||
        !grandir_serpent(&tete, 'B', 12, 10)){
        liberer_serpent(&tete);
        return EXIT_FAILURE;
    }
    printf("Taille du serpent: %d\n", calculer_taille(tete));
    liberer_serpent(&tete);
    return 0;
}
