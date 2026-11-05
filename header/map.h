#ifndef MAP_H
#define MAP_H
#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"

void map_create();
int map_correct(FILE* map);
int exists(const char *fname);

#endif