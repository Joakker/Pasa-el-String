#include "lib/macr_lib.h"
#include "lib/incl_lib.h"
#include "lib/iend_lib.h"
#include "lib/play_lib.h"
#include "lib/dict_lib.h"

int main(void){
        int numEntr       = count_entries();                                    //number of entries in the dictionary
        int limites[NLETRS];                                                    //number of entries per letter

        Entrada* database = (Entrada*) malloc(sizeof(Entrada) * numEntr);       //list of entries
        Directorio** dir  = (Directorio**) malloc(sizeof(Directorio*) * NLETRS);//directory of entries grouped by letter

        for (int i = 0; i < NLETRS ; ++i)
                dir[i] = (Directorio*) malloc(sizeof(Directorio)* numEntr);     //allocates memory for the entry pointers

        read_dictionary(numEntr, database);                                     //reads the dictionary text file
        sort_dictionary(numEntr, database, dir, limites);                       //classifies each entry into the directory

        initscr();                                                              //initializes screen on the terminal

        TITLE_SCREEN:

        for (int i = 1 ; i <= 6 ; i++)
                center(i + 4, title_row(i));

        switch (getch()) {
                case ESC_KEY:
                        goto END_SCREEN;
                case NLN_KEY:
                        goto GAME_SCREEN;
                }

        GAME_SCREEN:


        SCORE_SCREEN:


        END_SCREEN:
                endwin();
        return 0;
}
