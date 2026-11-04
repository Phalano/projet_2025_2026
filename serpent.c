#include <stdio.h>
#include <stdlib.h>
#include "serpent.h"

Serpent initialiser_serpent(int x_depart, int y_depart){
    Serpent nouv = (Serpent)malloc(sizeof(Cellule)); // alloue la mémoire pour le premier morceau du serpent
    if (nouv == NULL){
        fprintf(stderr,"Erreur d'allocation mémoire du serpent.\n");
        exit(EXIT_FAILURE); // Arrête immédiatement le programme et signale un échec au système
    }
    nouv->lettre = 'z'; //assigne la lettre 'z' 
    nouv->x = x_depart; //assigne la coordonnée x de départ 
    nouv->y = y_depart; //assigne la coordonnée y de départ
    nouv->suiv = NULL; //initialise le pointeur suivant à NULL car c'est le seul morceau
    return nouv;
}

void grandir_serpent(Serpent* tete, char nouvelle_lettre, int nouveau_x, int nouveau_y){
    Serpent nouveau_morceau = (Serpent)malloc(sizeof(Cellule)); // alloue la mémoire pour le nouveau morceau du serpent à ajouter
    if (nouveau_morceau == NULL){
        fprintf(stderr,"Erreur d'allocation mémoire pour l'évolution du serpent.\n");
        exit(EXIT_FAILURE);// Quitte le programme proprement en cas de mémoire saturée
    }

    nouveau_morceau->lettre = nouvelle_lettre; // ajoute la lettre mangé au nouveau morceau 
    nouveau_morceau->x = nouveau_x; // ajoute la nouvelle position x au nouveau morceau 
    nouveau_morceau->y = nouveau_y; // ajoute la nouvelle position y au nouveau morceau 
    
    //le nouveau morceau devient la tête et l'ancien la queue
    nouveau_morceau->suiv = *tete; // Relie le nouveau morceau à l'ancienne tête du serpent
    *tete = nouveau_morceau; // Met à jour la variable de tête pour pointer sur le nouveau morceau
}

int verifier_collision(Serpent tete, int nouv_x, int nouv_y){
    Serpent actuel = tete;
    while (actuel != NULL){
        if(actuel->x == nouv_x && actuel->y == nouv_y){
            return 1;
        }
        actuel = actuel->suiv;
    }
    return 0;
}

// Calcule le nombre total de morceau du corp du serpent
int calculer_taille(Serpent tete){
    int taille = 0; 
    Serpent actuel = tete; // 'actuel' pointera sur le même morceau que 'tete' et permet le déplacement de morceau en morceau
    
    while(actuel != NULL){ // tant que 'actuel' a un morceau qui existe dan la mémoire, il continue .
        taille = taille + 1; 
        actuel = actuel->suiv; // avance au morceau du serpent
    }
    return taille;
}

// libération de la mémoire à la fin d'une partie
void liberer_serpent(Serpent tete){
    Serpent actuel = tete;// 'actuel' pointera sur le même morceau que 'tete' et permet le déplacement de morceau en morceau
    
    while(actuel != NULL){
        Serpent supprimer = actuel; //'supprimer' prend le morceau dans 'actuel' 
        actuel = actuel->suiv; // avance au morceau du serpent
        free(supprimer); // efface le morceau
    }
}