#include <stdio.h>
#include <stdlib.h>
#include "serpent.h"

Serpent initialiser_serpent(int x_depart, int y_depart){
    Serpent nouv = malloc(sizeof *nouv);
    if (nouv == NULL){
        fprintf(stderr,"Erreur d'allocation mémoire du serpent.\n");
        return NULL;
    }
    nouv->lettre = 'z';// Initialisation de la lettre du serpent
    nouv->x = x_depart;// Initialisation de la position x du serpent
    nouv->y = y_depart;// Initialisation de la position y du serpent
    nouv->suiv = NULL;
    return nouv;// Retourne le pointeur vers le nouveau morceau du serpent
}

bool grandir_serpent(Serpent* tete, char nouvelle_lettre, int nouveau_x, int nouveau_y){
    if (tete == NULL){// Vérifie si le pointeur vers la tête du serpent est valide
        fprintf(stderr,"Erreur : pointeur vers la tête du serpent invalide.\n");
        return false;
    }

    Serpent nouveau_morceau = malloc(sizeof *nouveau_morceau);// Alloue de la mémoire pour le nouveau morceau du serpent
    if (nouveau_morceau == NULL){
        fprintf(stderr,"Erreur d'allocation mémoire pour l'évolution du serpent.\n");
        return false;
    }

    nouveau_morceau->lettre = nouvelle_lettre;// Assigne la lettre du nouveau morceau du serpent
    nouveau_morceau->x = nouveau_x;// Assigne la position x du nouveau morceau du serpent
    nouveau_morceau->y = nouveau_y;// Assigne la position y du nouveau morceau du serpent
    
    nouveau_morceau->suiv = *tete;// Le nouveau morceau pointe vers l'ancien morceau de tête du serpent
    *tete = nouveau_morceau;//  Met à jour la tête du serpent pour qu'elle pointe vers le nouveau morceau
    return true;
}

int verifier_collision(Serpent tete, int nouv_x, int nouv_y, const matrice* carte){
    if (carte == NULL || carte->elt == NULL){ // Vérifie si la carte est valide avant de vérifier la collision
        fprintf(stderr, "Erreur : carte invalide pour vérifier la collision.\n");
        return 1;
    }

    if (nouv_x < 0 || nouv_x >= carte->col ||
        nouv_y < 0 || nouv_y >= carte->lign){// Vérifie si les coordonnées du nouveau morceau sont en dehors des limites de la carte
        fprintf(stderr, "Erreur : nouvelles coordonnées en dehors des limites de la carte.\n");
        return 1;
    }

    if (matrice_get(carte, nouv_y, nouv_x) == '#'){// Vérifie si le nouveau morceau entre en collision avec un mur sur la carte
        fprintf(stderr, "Erreur : collision avec un mur.\n");
        return 1;
    }

    Serpent actuel = tete;// 'actuel' pointera sur le même morceau que 'tete' et permet le déplacement de morceau en morceau
    while (actuel != NULL){
        if(actuel->x == nouv_x && actuel->y == nouv_y){// Vérifie si les coordonnées du nouveau morceau correspondent à celles d'un morceau existant
            fprintf(stderr, "Erreur : collision avec le corps du serpent.\n");
            return 1;
        }
        actuel = actuel->suiv;// Passe au morceau suivant du serpent
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
void liberer_serpent(Serpent* tete){
    if (tete == NULL){// Vérifie si le pointeur vers la tête du serpent est valide
        fprintf(stderr,"Erreur : pointeur vers la tête du serpent invalide.\n");
        return;
    }

    Serpent actuel = *tete;// 'actuel' pointera sur le même morceau que 'tete' et permet le déplacement de morceau en morceau
    
    while(actuel != NULL){
        Serpent supprimer = actuel; // 'supprimer' pointe sur le morceau actuel du serpent qui sera libéré de la mémoire
        actuel = actuel->suiv; // avance au morceau suivant du serpent
        free(supprimer); // libère la mémoire du morceau actuel du serpent
    }
    *tete = NULL;// Met à jour le pointeur vers la tête du serpent pour qu'il pointe vers NULL, indiquant que le serpent a été libéré de la mémoire
}
