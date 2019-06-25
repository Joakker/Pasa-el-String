#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>

#include    <SDL2/SDL.h>
#include    <SDL2/SDL_ttf.h>
#include    <SDL2/SDL_image.h>

#include    "lib/dict_lib.h"
#include    "lib/macr_lib.h"
#include    "lib/iend_lib.h"

int main()
{
    /*  ######################
        ##VARIABLES AND SUCH##
        ######################  */
    int             numEntr;
    Entrada       * database;

    bool            game_loop;
    SDL_Event       window_events;

    SDL_Window    * window;
    SDL_Renderer  * renderer;
    SDL_Surface   * screen_surface;
    SDL_Texture   * title_screen;

    TTF_Font *font;

    /*  #########
        ##SETUP##
        #########   */
    numEntr     = count_entries();
    database    = malloc(sizeof(Entrada) * numEntr);
    font        = TTF_OpenFont("fnt/OpenSans-Light.ttf", 12);

    read_diccionary(numEntr, database);
    init_screen(&window, &renderer, &screen_surface, &title_screen);

    /*  #############
        ##GAME LOOP##
        #############   */

    while(game_loop)
    {
        while (SDL_PollEvent(&window_events))
        {
            if (window_events.type == SDL_QUIT) game_loop = false;
        }
        SDL_UpdateWindowSurface(window);
    }

    /*  ########
        ##EXIT##
        ########    */

    SDL_DestroyTexture(text);
    dstr_screen(&title_screen, &renderer, &window);
    return 0;
}
