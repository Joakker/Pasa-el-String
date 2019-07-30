#include "lib/macr_lib.h"
#include "lib/incl_lib.h"
#include "lib/iend_lib.h"
#include "lib/play_lib.h"
#include "lib/dict_lib.h"


int main(void){

        /*      ##########################
                ##SETUP AND DECLARATIONS##
                ##########################      */

        srand(time(NULL));

        int numEntr       = count_entries();                                    //number of entries in the dictionary
        int limites[NLETRS];                                                    //number of entries per letter

        Entrada* database = (Entrada*) malloc(sizeof(Entrada) * numEntr);       //list of entries
        //Directorio** dir  = init_directory(numEntr);                            //directory of entries grouped by letter

        read_dictionary(numEntr, database);                                     //reads the dictionary text file
        //sort_dictionary(numEntr, database, dir, limites);                       //classifies each entry into the directory

        Player* jugadores = init_players();                                     //Array containing both players
        bool    is_running= true;

        initscr();                                                              //initializes screen on the terminal
        if (has_colors()) start_color();                                        //initializes colours if possible

        WINDOW* name    = newwin(10, 30, (LINES / 2) - 5,(COLS / 2) - 15);      //pointer to the 'introduce your name' screen
        WINDOW* score   = newwin(0, 0, 0, 0);                                   //pointer to the scores window


        WINDOW* game    = newwin(0, 0, 0, 0);                                   //pointer to the game window
        WINDOW* pinfo1  = subwin(game, (LINES / 2), 30, 0, 0);                  //player 1's info
        WINDOW* pinfo2  = subwin(game, (LINES / 2), 30, (LINES / 2), 0);        //player 2's info
        WINDOW* define  = subwin(game, 10, (COLS - 31), 0, 31);                 //definition of the current word
        WINDOW* answer  = subwin(game, 5, 30, 20 , (COLS / 2));                 //player's answer
        //WINDOW* hint    = subwin(game, 5, 30, 11 , (COLS / 2));

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


        bool activo = false;
        Entrada* current;
        char answ[MAXLTR];
        draw_info(1);
        draw_info(2);                                     //draws the players' info on the side of the screen

        while (is_running) {
                box(define, 0, 0);
                box(answer, 0, 0);
                //box(hint,   0, 0);
                wrefresh(game);


                current = search(numEntr, database, 'a' + jugadores[activo].cur_letter);
                center(5, current->definicion, define);
                center(6, "Contiene la ", define);
                waddch(define, 'A' + jugadores[activo].cur_letter);
                wrefresh(define);

                mvwscanw(answer, 2, 3, "%s", answ);

                if (compare(answ, current->palabra)) {
                        jugadores[activo].cur_letter++;
                        jugadores[activo].time -= (unsigned char) strlen(answ);
                        jugadores[activo].successes++;
                } else if (compare(answ, "Pasapalabra")) {
                        activo = (activo == true)? false : true;
                } else {
                        jugadores[activo].time -= strlen(answ);
                        jugadores[activo].mistakes++;
                        activo = (activo == true)? false : true;
                }

                werase(game);

                draw_info(1);
                draw_info(2);
                for (int i = 0 ; i < 2; i++)
                        if (jugadores[i].time <= 0 || jugadores[i].cur_letter >= NLETRS) is_running = false;
        }


        WINDOW* ganador = newwin(10, 30, (LINES / 2) - 5, (COLS / 2) - 5);
        Player  win = winner(jugadores);
        center(4, "El ganador es:", ganador);
        center(5, win.name, ganador);
        box(ganador, 0, 0);
        wrefresh(ganador);
        getch();
	FILE* scores = fopen("txt/highscores.txt", "a");
	fprintf(scores, "%s\t%d\t%d\t%d\n",win.name, win.successes, win.mistakes, win.time);
        END_SCREEN:

        endwin();
        return 0;
}
