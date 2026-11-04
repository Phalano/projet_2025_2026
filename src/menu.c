#include <stdio.h>
#include <stdlib.h>

void AfficherMenu(void){
    printf("|| ========================= ||\n");
    printf("             SNAKE             \n");
    printf("|| ========================= ||\n");
    printf("    Choisissez de 1-4 :        \n");
    printf("    1-Lancer le jeu            \n");
    printf("    2-Score                    \n");
    printf("    3-Difficile                \n");
    printf("    4-Lorem Ipsum              \n");
}

int main(void){
    AfficherMenu();
    return EXIT_SUCCESS;
}



