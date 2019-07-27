#include <stdio.h>
#include <stdlib.h>
#include "lib/macr_lib.h"
#include "lib/dict_lib.h"

int main(void) {
        int numEntr = count_entries();
        int limites[NLETRS];
        Entrada* database = (Entrada*) malloc(sizeof(Entrada) * numEntr);
        Directorio** dir  = (Directorio**) malloc(sizeof(Directorio*) * NLETRS);

        for (int i = 0; i < numEntr ; i++) {
                dir[i] = (Directorio*) malloc(sizeof(Directorio)*numEntr);
        }

        read_dictionary(numEntr, database);
        sort_dictionary(numEntr, database, dir, limites);

        for(int i = 0; i < NLETRS ; i++) {
                for (int j = 0; j < limites[i] ; ++j){
                        printf("%d %s\n",1 + i + j, dir[i][j].entrada->palabra);
                }
        }
}
