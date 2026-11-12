#include <stdio.h>
#include <stdlib.h>
#include "serpent.h"


int main(){
    matrice* carte = matrice_create(5, 7); // Crée une matrice de 5 colonnes et 7 lignes pour représenter la carte du jeu
    if (carte == NULL){
        fprintf(stderr, "Erreur d'allocation de la carte.\n");
        return EXIT_FAILURE;
    }
    matrice_null(carte);

    int x;// Déclaration de la variable x pour les boucles
    int y;// Déclaration de la variable y pour les boucles
    for (x = 0; x < carte->col; x++){// Boucle pour placer des murs sur les bords de la carte
        matrice_set(carte, 0, x, '#');// Place un mur en haut de la carte
        matrice_set(carte, carte->lign - 1, x, '#');// Place un mur en bas de la carte
    }
    for (y = 0; y < carte->lign; y++){
        matrice_set(carte, y, 0, '#');// Place un mur à gauche de la carte
        matrice_set(carte, y, carte->col - 1, '#');// Place un mur à droite de la carte
    }
    matrice_set(carte, 3, 2, '#');// Place un mur à la position (3, 2) sur la carte

    Serpent tete = initialiser_serpent(1, 1);
    if (tete == NULL){
        matrice_free(carte);// Libère la mémoire de la carte avant de quitter en cas d'erreur
        fprintf(stderr, "Erreur d'allocation du serpent.\n");
        return EXIT_FAILURE;
    }

    if (!grandir_serpent(&tete, 'A', 2, 1) ||
        !grandir_serpent(&tete, 'B', 3, 1)){
        liberer_serpent(&tete);
        matrice_free(carte);
        return EXIT_FAILURE;
    }

    if (!verifier_collision(tete, 5, 1, carte) ||
        !verifier_collision(tete, 0, 1, carte) ||
        !verifier_collision(tete, 2, 3, carte) ||
        !verifier_collision(tete, 3, 1, carte) ||
        verifier_collision(tete, 1, 2, carte)){
        fprintf(stderr, "Erreur lors des tests de collision.\n");
        liberer_serpent(&tete);
        matrice_free(carte);
        return EXIT_FAILURE;
    }

    printf("Taille du serpent: %d\n", calculer_taille(tete));
    liberer_serpent(&tete);
    matrice_free(carte);
    return 0;
}
