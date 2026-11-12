#include <stdio.h>
#include "../header/jeu.h"

static int i = 0;

void LancerJeu(void){
    printf("--- Lancement d'une partie ---\n");
    i++;
}

void AfficherScore(void){
    int score = 100; //Initialisation de score pour ne pas faire apparaître une valeur imprévue
    
    printf("|| ========================= ||\n");
    printf("             SCORE             \n");
    printf("|| ========================= ||\n");
    printf("Valeur de i (nombre de parties lancées) : %d\n", i); //Test pour voir si i peut être utilisé dans +sieurs fonctions
    printf("Votre score est : %d\n", score); //Affichage du score
}

void Difficulte(void){
    // Va augmenter la difficulté 
}

void EasterEgg(void){
    //Petite blague
}

int main(void){
    AfficherScore();
    LancerJeu();

    LancerJeu();
    AfficherScore();
}

