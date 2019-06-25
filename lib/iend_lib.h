#ifndef IEND_LIB_H_INCLUDED
#define IEND_LIB_H_INCLUDED


void init_screen(SDL_Window**   window,
                 SDL_Renderer** renderer,
                 SDL_Surface**  screen_surface,
                 SDL_Texture**  title_screen) {

    if(SDL_Init(IFLAGS)) {
        printf("Error initializing SDL: %s", SDL_GetError());
        exit(1);
    }

    *window = SDL_CreateWindow(WTITLE, CENTER, CENTER, WIDTH, HEIGHT, 0);
    if (*window == NULL) {
        printf("Error creating window: %s", SDL_GetError());
        SDL_Quit();
        exit(1);
    }

    *renderer   = SDL_CreateRenderer(*window, -1, RFLAGS);
    if (*renderer == NULL) {
        printf("Error creating renderer: %s", SDL_GetError());
        SDL_DestroyWindow(*window);
        SDL_Quit();
        exit(1);
    }

    *screen_surface = IMG_Load("img/title.bmp");
    if (*screen_surface == NULL) {
        printf("Error loading surface: %s", SDL_GetError());
        SDL_DestroyRenderer(*renderer);
        SDL_DestroyWindow(*window);
        SDL_Quit();
        exit(1);
    }

    *title_screen   = SDL_CreateTextureFromSurface(*renderer, *screen_surface);
    if (*title_screen == NULL) {
        printf("Error loading screen: %s", SDL_GetError());
        SDL_FreeSurface(*screen_surface);
        SDL_DestroyRenderer(*renderer);
        SDL_DestroyWindow(*window);
        SDL_Quit();
        exit(1);
    }



    SDL_RenderClear(*renderer);
    SDL_RenderCopy(*renderer, *title_screen, NULL, NULL);
    SDL_FreeSurface(*screen_surface);
    SDL_RenderPresent(*renderer);

}

void dstr_screen(SDL_Texture**  title_screen,
                 SDL_Renderer** renderer,
                 SDL_Window**   window) {

    SDL_DestroyTexture(*title_screen);
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_Quit();

}

#endif // IEND_LIB_H_INCLUDED
