#include <stdlib.h>
#include <ncurses.h>

#include "lib/macr_lib.h"
#include "lib/dict_lib.h"

int main(void){
        int numEntr = count_entries();
        int limites[NLETRS];
        Entrada* database        = (Entrada*) malloc(sizeof(Entrada) * numEntr);
        Directorio** directorio  = (Directorio**) malloc(sizeof(Directorio*) * NLETRS);
        for (int i = 0; i < NLETRS ; ++i) directorio[i] = (Directorio*) malloc(sizeof(Directorio)* numEntr);

        read_dictionary(numEntr, database);
        sort_dictionary(numEntr, database, directorio, limites);


        return 0;
}
