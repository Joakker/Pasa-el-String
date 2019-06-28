#include    <stdio.h>
#include    <stdlib.h>

#include    <SDL2/SDL.h>
#include    <SDL2/SDL_ttf.h>
#include    <SDL2/SDL_image.h>
#include    <SDL2/SDL_timer.h>
#include    <SDL2/SDL_mixer.h>

#include    "lib/macr_lib.h"
#include    "lib/play_lib.h"

int main(void) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    Mix_Init(MIX_INIT_MP3);

    SDL_Window* gameWindow = SDL_CreateWindow(WTITLE, CENTER,CENTER,
                                              WIDTH, HEIGHT, WFLAGS);

    SDL_Surface* windowSurface  = SDL_GetWindowSurface(gameWindow);
    SDL_Surface* titleScreen    = SDL_LoadBMP("img/img1.bmp");
    SDL_Surface* gamesScreen    = SDL_LoadBMP("img/img2.bmp");
    SDL_Surface* scoreScreen    = SDL_LoadBMP("img/img3.bmp");
    SDL_Surface* currentScreen  = titleScreen;

    SDL_Event wEvents;
    SDL_bool  isRunnning = SDL_TRUE;

    while(isRunnning){
        while(SDL_PollEvent(&wEvents)){
            if (wEvents.type == SDL_QUIT) isRunnning = SDL_FALSE;
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
                        isRunnning = SDL_FALSE;
                }
        }
        SDL_BlitSurface(currentScreen, NULL, windowSurface, NULL);
        SDL_UpdateWindowSurface(gameWindow);
    }


    SDL_FreeSurface(titleScreen);
    SDL_FreeSurface(gamesScreen);
    SDL_FreeSurface(scoreScreen);
    SDL_DestroyWindow(gameWindow);
    Mix_Quit();
    SDL_Quit();
    return 0;
}
