#include <SDL.h>
#include <stdio.h>
#include <math.h>
#include "App.h"


// Constants for screen dimensions
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main (int argc, char* argv[]) {

    SDL_Window* window = NULL;
    App app = NULL;

    // Initialize SDL & create the window
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    } else {
        window = SDL_CreateWindow("Pizza Frank", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        } else {
            // Construct the App & initialize its contents
            app = App(window);
            app.init();

            // Set up some ints for timing FPS
            Uint32 last = 0, now = SDL_GetTicks(), deltaTime = 0;
            float fps = 0.0f;

            // Event used to capture through poll event
            SDL_Event event;

            // renderer sent to the App
            SDL_Renderer* renderer = NULL;
            renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);

            bool quit = false;
            while (!quit) {

                while (SDL_PollEvent(&event)) {
                    // route the event to the App
                    app.onEvent(&event);

                    // Quit if escape is pressed
                    if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE)
                        quit = true;
                }

                // Calculate the FPS
                last = now;
                now = SDL_GetTicks();
                deltaTime = now - last;
                if (deltaTime != 0)
                    fps = 1000.0f/deltaTime;
                else
                    fps = 0.0f;

                // Let app do its thing
                quit = app.update(deltaTime);

                // Get the draw data from the sprites and then render to the screen
                app.draw(renderer);
                SDL_RenderPresent(renderer);

                // If we are quitting the App, make it clean up
                if (quit)
                    app.cleanup();
            }

        }

         //Destroy window
         SDL_DestroyWindow( window );

         //Quit SDL subsystems
         SDL_Quit();

         return 0;

    }
    return 0;

}
