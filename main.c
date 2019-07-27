#include "lib/macr_lib.h"
#include "lib/incl_lib.h"
#include "lib/iend_lib.h"
#include "lib/play_lib.h"
#include "lib/dict_lib.h"

int main(void){

        /*      ##########################
                ##SETUP AND DECLARATIONS##
                ##########################      */


        int numEntr       = count_entries();                                    //number of entries in the dictionary
        int limites[NLETRS];                                                    //number of entries per letter

        Entrada* database = (Entrada*) malloc(sizeof(Entrada) * numEntr);       //list of entries
        Directorio** dir  = init_directory(numEntr);                            //directory of entries grouped by letter

        read_dictionary(numEntr, database);                                     //reads the dictionary text file
        sort_dictionary(numEntr, database, dir, limites);                       //classifies each entry into the directory

        Player* jugadores = init_players();                                     //Array containing both players
        bool    j1_activo = true;                                               //switch between both players
        bool    is_running= true;

        initscr();                                                              //initializes screen on the terminal
        if (has_colors()) start_color();                                        //initializes colours if possible

        WINDOW* game    = newwin(0, 0, 0, 0);                                   //pointer to the game window
        WINDOW* name    = newwin(10, 30, (LINES / 2) - 5,(COLS / 2) - 15);      //pointer to the 'introduce your name' screen

        WINDOW* score   = newwin(0, 0, 0, 0);                                   //pointer to the scores window
        WINDOW* timer   = subwin(game, 5, 20, 1, 1);                            //pointer to the timer window






        TITLE_SCREEN:

        for (int i = 1 ; i <= 6 ; i++)  center(i + 4, title_row(i), stdscr);    //draws the title line by line
        box(stdscr, 0, 0);                                                      //creates a box around the screen

        attron(A_BOLD);                                                         //text will appear bold
        center(LINES - 5, "Presione ENTER para comenzar el juego", stdscr);     //subtitle instruction
        center(LINES - 4, "Presione ESC para salir", stdscr);                   //subtitle instruction
        attroff(A_BOLD);                                                        //text won't appear bold


        switch (getch()) {                                                      //gets a key in order to continue
                case ESC_KEY:   goto END_SCREEN;                                //escape to exit
                case NLN_KEY:   goto GAME_SCREEN;                               //enter to proceed to fame screen
                default:        goto TITLE_SCREEN;                              //otherwise the process repeats again
        }




        GAME_SCREEN:

        for (int i = 0 ; i < 2 ; i++) {
                wclear(name);
                center(3, "Introducir nombre", name);                           //title instruction
                center(5, "Jugador n° ", name);                                 //title reference
                waddch(name,'1'+ i);                                            //number of the player
                box(name, 0, 0);                                                //redraws the border box
                wrefresh(name);                                                 //refreshes the window
                mvwscanw(name, 6, 4, "%s", jugadores[i].name);                  //gets the name of both players
        }



        mvwprintw(game, 10, 10, "Hello world!");
        wrefresh(game);
        getch();




        SCORE_SCREEN:


        END_SCREEN:
                endwin();
        return 0;
}
