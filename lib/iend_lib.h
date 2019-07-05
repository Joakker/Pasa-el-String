#ifndef IEND_LIB_H_INCLUDED
#define IEND_LIB_H_INCLUDED

void noop() {
  return;
}

void init_screen( SDL_Window** gameWindow, Mix_Music** bgm,
                  SDL_Surface** windowSurface, SDL_Surface** titleScreen,
                  SDL_Surface** gamesScreen, SDL_Surface** scoreScreen,
                  SDL_Surface** currentScreen) {


    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO);
    *gameWindow = SDL_CreateWindow( WTITLE, CENTER,CENTER,
                                    WIDTH, HEIGHT, WFLAGS);

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    * bgm            = Mix_LoadMUS("mp3/bgm.mp3");
    * windowSurface  = SDL_GetWindowSurface(*gameWindow);
    * titleScreen    = SDL_LoadBMP("img/img1.bmp");
    * gamesScreen    = SDL_LoadBMP("img/img2.bmp");
    * scoreScreen    = SDL_LoadBMP("img/img3.bmp");
    * currentScreen  = *titleScreen;
    SDL_StartTextInput();
    Mix_PlayMusic(*bgm, -1);
}

void dstr_screen( Mix_Music** bgm, SDL_Surface** titleScreen,
                  SDL_Surface** gamesScreen, SDL_Surface** scoreScreen,
                  SDL_Window** gameWindow) {
  SDL_StopTextInput();
  Mix_FreeMusic(*bgm);
  SDL_FreeSurface(*titleScreen);
  SDL_FreeSurface(*gamesScreen);
  SDL_FreeSurface(*scoreScreen);
  SDL_DestroyWindow(*gameWindow);
  Mix_Quit();
  SDL_Quit();
}
#endif // IEND_LIB_H_INCLUDED
