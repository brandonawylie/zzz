#ifndef _APP_H
	#define _APP_H

#include "EventListener.h"
#include <SDL.h>

class App: public EventListener{
    public:
        App(SDL_Window* window);
        ~App();
        void init();
        void cleanup();
        /**
        *   update all the app, and all the game components contained in it.
        *   @param deltaTime milliseconds passed since last update
        *   @returns boolean indicating if you want to quit (true=quit)
        */
        bool update(Uint32 deltaTime);
        void draw(SDL_Renderer* renderer);
        void onEvent(SDL_Event* event);
        void onKeyDown(SDL_Keycode sym);
    private:
        SDL_Window* window;
};

#endif
