#include    <stdio.h>
#include    <stdlib.h>

#include    <SDL2/SDL.h>
#include    <SDL2/SDL_ttf.h>
#include    <SDL2/SDL_image.h>
#include    <SDL2/SDL_timer.h>
#include    <SDL2/SDL_mixer.h>

#include    "lib/macr_lib.h"
#include    "lib/play_lib.h"
#include    "lib/iend_lib.h"
#include    "lib/dict_lib.h"

int main(void) {


    /*      #########################
            ####DECLARE VARIABLES####
            #########################     */

    SDL_Window *  gameWindow;
    Mix_Music  *  bgm;
    SDL_Surface*  windowSurface;
    SDL_Surface*  titleScreen;
    SDL_Surface*  gamesScreen;
    SDL_Surface*  scoreScreen;
    SDL_Surface*  currentScreen;

    int   numEntr     = count_entries();
    int*  limites     = (int*) malloc(sizeof(int) * NLETRS);
    Entrada* database = (Entrada*) malloc(sizeof(Entrada) * numEntr);
    Directorio** dir  = (Directorio**) malloc(sizeof(Directorio*) * NLETRS);

    float frameTime = 0;
    int   prevTime  = 0;
    int   currTime  = 0;
    float deltaTime = 0;

    SDL_Event wEvents;
    bool  isRunnning = true;

    for ( int i = 0 ; i < NLETRS ; i++)
      dir[i] = (Directorio*) malloc(sizeof(Directorio) * numEntr);


    /*      ###############################################
            ####INITIALIZATION AND ENTERING THE PROGRAM####
            ###############################################     */


    init_screen(&gameWindow, &bgm, &windowSurface, &titleScreen,
                &gamesScreen, &scoreScreen, &currentScreen);

    read_dictionary(numEntr, database);
    sort_dictionary(numEntr, database, dir, limites);

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



    dstr_screen(&bgm, &titleScreen, &gamesScreen, &scoreScreen, &gameWindow);

    for ( int i = 0 ; i < numEntr ; i++) free(dir[i]);
    free(dir);
    free(limites);
    free(database);
    return 0;
}
