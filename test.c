#include <stdio.h>
#include <stdlib.h>
#include "lib/macr_lib.h"
#include "lib/dict_lib.h"


int main(void) {
        int numEntr = count_entries();
        //int limites[NLETRS];
        Entrada* database = (Entrada*) malloc(sizeof(Entrada) * numEntr);
        //Directorio** dir  = (Directorio**) malloc(sizeof(Directorio*) * NLETRS);


        read_dictionary(numEntr, database);
        //sort_dictionary(numEntr, database, dir, limites);

        srand(time(NULL));

        for (int i = 0; i < NLETRS; i++) {
                Entrada* a = search(numEntr, database, 'a'+i);
                printf("%s\n", a->palabra);
        }
}
