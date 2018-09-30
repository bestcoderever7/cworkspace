#include "SDL/SDL.h"

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("title", 0, 0, 800, 800, 0);
    SDL_Event event;
    while(running){
        while(!SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN
                    if(event.key.keysym.sym == SDLK_ESCAPE){
                        running = false;
                    }
            }
        }
    }
    SDL_DestroyWindow(window);
    return 0;
}