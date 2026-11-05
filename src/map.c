#include "../header/map.h"
#include "../header/matrice.h"
#include <stdio.h>
#include <stdlib.h>

// Source - https://stackoverflow.com/q/230062
// Posted by Dave Marshall, modified by community. See post 'Timeline' for change history
// Retrieved 2026-11-04, License - CC BY-SA 4.0
int exists(const char *fname)
{
    FILE *file;
    if ((file = fopen(fname, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}

//Verifie si la map dans le fichier map.txt est correcte

int map_correct(FILE* map){
    int i, j, n, m, p;
    char o, k;
    for(i = 1; i < 6; i++){
        for(j = 1; j < 4; j++){
            fscanf(map, "%d", &m);
            if(m != 0){
                fclose(map);
                return 0;
            }
        }
    }
    for(n = 0; n < 7; n++){
        fscanf(map, "%c", &o);
        if(o != '#'){
            fclose(map);
            return 0;
        }
    }
    for(p = 0; p < 5; p++){
        fscanf(map, "%c", &k);
        if(k != '#'){
            fclose(map);
            return 0;
        }
    }
    
    fclose(map);
    return 1;
}


//Creer la map, et la sauvegarde dans le fichier map.txt dans le dossier bin, il le creer si il n'existe pas

void map_create(){
    if(exists("../bin/map.txt") == 1){
        if(map_correct("../bin/map.txt") == 1){
            FILE* fp = fopen("../bin/map.txt", "r");
            matrice* mp = matrice_file(fp);
            return mp;
        }
    }
    FILE* fp = fopen("../bin/map.txt", "w");
    matrice* m = matrice_create(5, 7);
    int i, j;
    matrice_null(m);
    for(i = 0;  i < m->col; i++){
        matrice_set(m, 0, i, "#");
        matrice_set(m, 6, i, "#");
    }
    for(j = 0; j < m->lign; j++){
        matrice_set(m, j, 0, "#");
        matrice_set(m, j, 4, "#");
    }
    matrice_save(m, fp);
    fclose(fp);
}