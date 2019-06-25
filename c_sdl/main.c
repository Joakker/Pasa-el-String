#include 	<stdio.h>
#include 	<SDL2/SDL.h>
#include	<SDL2/SDL_ttf.h>
#include	<SDL2/SDL_image.h>
#include	<SDL2/SDL_mixer.h>

int main(int argc, char const *argv[]) {

	const int FPS = 60;
	int frameTime = 0;
	SDL_Window *window;
  	SDL_Texture *currentImage;
  	SDL_Renderer *renderer;
  	SDL_Rect playerRect;

	int frameWidth, frameHeight;
  	int textureWidth, textureHeight;


  	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
  	if (TTF_Init() < 0 ) printf("Error\n");

  	int imgFlags = IMG_INIT_JPG;
  	IMG_Init(imgFlags);

  	window = SDL_CreateWindow("SDL tuto", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
  	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  	currentImage = IMG_LoadTexture(renderer, "sprite.jpg");

  	SDL_QueryTexture(currentImage, NULL, NULL, &textureWidth, &textureHeight);
  	frameWidth = textureWidth/9;
  	frameHeight = textureHeight/2;

  	playerRect.x = playerRect.y = 0;
  	playerRect.w = frameWidth;
  	playerRect.h = frameHeight;

  	TTF_Font *font = TTF_OpenFont("SIXTY.TTF", 20);
  	SDL_Color color = {144, 77, 255, 255};
  	SDL_Surface *textSurface = TTF_RenderText_Solid(font, "Hello world! :3", color);
  	SDL_Texture *text = SDL_CreateTextureFromSurface(renderer, textSurface);
  	SDL_FreeSurface(textSurface);
  	SDL_Rect textRect;
  	textRect.x = textRect.y = 0;

  	SDL_QueryTexture(text, NULL, NULL, &textRect.w, &textRect.h);

    if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2048) < 0 ) printf("Error");

    Mix_Music * bgm = Mix_LoadMUS("bgm.mp3");

  	SDL_bool isRunning = SDL_TRUE;
  	SDL_Event ev;

  	while (isRunning) {
  		while (SDL_PollEvent(&ev))
            if (ev.type == SDL_QUIT) isRunning = SDL_FALSE;
            else if (ev.type == SDL_KEYDOWN) {
                switch (ev.key.keysym.sym) {
                    case SDLK_p:
                        if(!Mix_PlayingMusic()) {
                            Mix_PlayMusic(bgm, -1);
                        }   else if (Mix_PausedMusic()) {
                                Mix_ResumeMusic();
                        }   else Mix_PauseMusic();
                        break;
                    case SDLK_s:
                        Mix_HaltMusic();
                        break;
                }
            }

  		frameTime ++;

  		if(FPS/frameTime == 4) {
  			frameTime = 0;
  			playerRect.x += frameWidth;
  			if(playerRect.x >= textureWidth) playerRect.x = 0;
  		}
  		SDL_RenderClear(renderer);
  		SDL_RenderCopy(renderer, currentImage, &playerRect, NULL);
  		SDL_RenderCopy(renderer, text, NULL, &textRect);
  		SDL_RenderPresent(renderer);
  	}

  	Mix_FreeMusic(bgm);
  	SDL_DestroyTexture(text);
  	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_CloseFont(font);
	Mix_Quit();
	TTF_Quit();
	IMG_Quit();
  	SDL_Quit();
  	return 0;
}
