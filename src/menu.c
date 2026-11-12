#include <stdio.h>
#include "menu.h"
#include "jeu.h"

// Cette  procédure affiche le menu par des printf()
void AfficherMenu(void){
    printf("|| ========================= ||\n");
    printf("             SNAKE             \n");
    printf("|| ========================= ||\n");
    printf("    Choisissez de 1-4 :        \n");
    printf("    1-Lancer le jeu            \n");
    printf("    2-Score                    \n");
    printf("    3-Difficulté               \n");
    printf("    4-Easter Egg               \n");
}

int InputJoueur(void){
    int demande;
    scanf("%d\n", &demande);
    printf("%d\n", demande);

    if (demande == 1){
        LancerJeu();
        return 0;
    }
    else if (demande == 2){
        AfficherScore();
        return 0;
    }
    else if (demande == 3){
        Difficulte();
        return 0;
    }
    else if (demande == 4){
        EasterEgg();
        return 0;
    }

}







