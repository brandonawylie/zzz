#ifndef _APP_H
	#define _APP_H

#include "EventListener.h"
#include <SDL.h>

class App: public EventListener{
    public:
        App(SDL_Window* window);
        ~App();

        /**
        * Initialize all the components of this
        */
        void init();

        /**
        * Clean up all the components contained within this
        */
        void cleanup();

        /**
        *   update all the app, and all the game components contained in it.
        *   @param deltaTime milliseconds passed since last update
        *   @returns boolean indicating if you want to quit (true=quit)
        */
        bool update(Uint32 deltaTime);

        /**
        * Draw the Sprite & all sub-components
        * @param renderer Use it for all your SDL rendering needs (don't render this to the screen)
        */
        void draw(SDL_Renderer* renderer);

        /**
        * Callback for when an event happens
        * @param event the SDL_Event that happened
        */
        void onEvent(SDL_Event* event);

        /**
        * Callback for when a key is pressed
        * @param sym the key symbol that was pressed (use sym.sym)
        */
        void onKeyDown(SDL_Keycode sym);

        /**
        * Callback for when a key is released
        * @param sym the key symbol that was released (use sym.sym)
        */
        void onKeyUp(SDL_Keycode sym);

    private:
        SDL_Window* window;
};

#endif
