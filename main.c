#include    <stdio.h>
#include    <stdlib.h>

#include    <SDL2/SDL.h>
#include    <SDL2/SDL_ttf.h>
#include    <SDL2/SDL_image.h>
#include    <SDL2/SDL_timer.h>
#include    <SDL2/SDL_mixer.h>

#include    "lib/macr_lib.h"                                                    //Contains the macros used throughout the program
#include    "lib/play_lib.h"                                                    //All the structures and functions relevant to the player
#include    "lib/iend_lib.h"                                                    //Setup and exit functions
#include    "lib/dict_lib.h"                                                    //Dictionary fuctions

int main(void) {


    /*      #########################
            ####DECLARE VARIABLES####
            #########################     */

    SDL_Window *  gameWindow;                                                   //This is the displayed window
    Mix_Music  *  bgm;                                                          //Background music
    SDL_Surface*  windowSurface;                                                //Window's surface (duh)
    SDL_Surface*  titleScreen;                                                  //Title screen image
    SDL_Surface*  gamesScreen;                                                  //Game screen background
    SDL_Surface*  scoreScreen;                                                  //Score screen background
    SDL_Surface*  currentScreen;

    int       numEntr = count_entries();                                        //Contains the number of entries in the dictionary
    int*      limites = (int*) malloc(sizeof(int) * NLETRS);                    //Contains the number of entries that begin with each letter
    Entrada* database = (Entrada*) malloc(sizeof(Entrada) * numEntr);           //Contains all the entries, word and definition separated
    Directorio**  dir = (Directorio**) malloc(sizeof(Directorio*) * NLETRS);    //Directory matrix of all the words
    for ( int i = 0 ; i < NLETRS ; i++)                                         //Every row contains all words beginning with one letter
      dir[i] = (Directorio*) malloc(sizeof(Directorio) * numEntr);              //Every cell points to an entry and contains which letters it has

    float frameTime = 0;
    int   prevTime  = 0;
    int   currTime  = 0;
    float deltaTime = 0;

    SDL_Event wEvents;                                                          //Handles all the events like clicks and keyboard typings
    bool  isRunnning = true;                                                    //Holds the game loop going



    /*      ###############################################
            ####INITIALIZATION AND ENTERING THE PROGRAM####
            ###############################################     */


    init_screen(&gameWindow, &bgm, &windowSurface, &titleScreen,                //Initializes the screen
                &gamesScreen, &scoreScreen, &currentScreen);                    //Takes care of loading the music and backgrounds

    read_dictionary(numEntr, database);                                         //Creates the list of entries on the heap
    sort_dictionary(numEntr, database, dir, limites);                           //Classifies each entry on the directory matrix

    if (check_dictionary(limites)){
      printf("Error de inicializacion\n");
      goto final;
    }

    /*      #################
            ####GAME LOOP####
            #################      */

    while(isRunnning){
        prevTime  = currTime;
        currTime  = SDL_GetTicks();
        deltaTime = (currTime - prevTime)/1000.0;

        frameTime += deltaTime;

        if (frameTime >= 1.0) {
          noop();
        }

        while(SDL_PollEvent(&wEvents)){
            if (wEvents.type == SDL_QUIT) isRunnning = false;
            else if (wEvents.type == SDL_KEYDOWN)
                switch (wEvents.key.keysym.sym) {
                    case SDLK_1:
                        currentScreen = titleScreen;
                        break;
                    case SDLK_2:
                        currentScreen = gamesScreen;
                        break;
                    case SDLK_3:
                        currentScreen = scoreScreen;
                        break;
                    case SDLK_ESCAPE:
                        isRunnning = false;
                }
        }

        SDL_BlitSurface(currentScreen, NULL, windowSurface, NULL);
        SDL_UpdateWindowSurface(gameWindow);
    }



    /*      ########################################
            ####CLEANING AND EXITING THE PROGRAM####
            ########################################      */


final:

    dstr_screen(&bgm, &titleScreen, &gamesScreen, &scoreScreen, &gameWindow);   //Destroys the screen and frees all the resources

    for ( int i = 0 ; i < numEntr ; i++) free(dir[i]);
    free(dir);
    free(limites);
    free(database);
    return 0;
}
