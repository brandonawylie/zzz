#include "../include/App.h"
#include "../include/Sprite.h"
#include <stdio.h>
#include <SDL.h>

App::App(SDL_Window* window) {
    this->window = window;

}

App::~App() {

}

void App::init() {

}

void App::cleanup() {

}

bool App::update(Uint32 dt){

    return false;
}

void App::draw(SDL_Renderer* renderer) {

}

void App::onEvent(SDL_Event* event) {
    EventListener::onEvent(event);
}

void App::onKeyDown(SDL_Keycode sym) {
    /*
    if (sym == SDLK_w) {
        playerEx.y-=4;
    }

    if (sym == SDLK_s) {
        playerEx.y+=4;
    }

    if (sym == SDLK_a) {
        playerEx.x-=4;
    }

    if (sym == SDLK_d) {
        playerEx.x+=4;
    }
    */
}

void App::onKeyUp(SDL_Keycode sym){}
