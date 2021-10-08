#include "SDL.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    
    SDL_Window* window = SDL_CreateWindow(
        "SDL2Test",
        30,
        30,
        640,
        480,
        SDL_WINDOW_SHOWN
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Surface* screen = SDL_GetWindowSurface(window);


    SDL_Delay(3000);

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}