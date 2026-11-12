#include <stdio.h>
#include "../header/matrice.h"

int main(void)
{
    FILE* fp;
    matrice* m;

    /* Création du fichier */
    fp = fopen("sauvegarde/carte.txt", "w");

    if (fp == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 1;
    }

    /* Création d'une matrice de 5 colonnes et 7 lignes */
    m = matrice_create(5, 7);

    if (m == NULL) {
        fprintf(stderr, "Erreur lors de la creation de la matrice\n");
        fclose(fp);
        return 1;
    }

    /* Initialisation de la matrice */
    matrice_null(m);

    /* Sauvegarde dans le fichier */
    matrice_save(m, fp);

    /* Vérification de l'écriture */
    if (ferror(fp)) {
        fprintf(stderr, "Erreur lors de la sauvegarde\n");
        fclose(fp);
        matrice_free(m);
        return 1;
    }

    /* Fermeture du fichier */
    if (fclose(fp) != 0) {
        perror("Erreur lors de la fermeture du fichier");
        matrice_free(m);
        return 1;
    }

    /* Affichage de la matrice */
    matrice_print(m);

    /* Libération de la mémoire */
    matrice_free(m);

    return 0;
}
