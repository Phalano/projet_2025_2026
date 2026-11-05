#include <stdio.h>
#include <stdlib.h>
#include "serpent.h"
int main(int argc, char *argv[]) {
    printf("=== Test du Serpent ===\n\n");
    // 1. On initialise le serpent en haut à gauche (coordonnées x=0, y=0)
    Serpent mon_serpent = initialiser_serpent(0, 0);
    
    // On affiche sa position de départ
    printf("Position initiale - Lettre: %c, x: %d, y: %d\n", 
           mon_serpent->lettre, mon_serpent->x, mon_serpent->y);
    printf("Taille actuelle: %d\n\n", calculer_taille(mon_serpent));
    
    liberer_serpent(mon_serpent);
    printf("Mémoire du serpent libérée avec succès.\n");
    return 0;
}
