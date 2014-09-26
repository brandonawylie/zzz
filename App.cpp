#include "App.h"
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
    SDL_Rect r;
    r.x = 50;
    r.y = 50;
    r.w = 50;
    r.h = 50;
    SDL_SetRenderDrawColor(renderer, 0, 100, 100, 255);
    SDL_RenderFillRect(renderer, &r);
}

void App::onEvent(SDL_Event* event) {
    EventListener::onEvent(event);
}

void App::onKeyDown(SDL_Keycode sym) {

    if (sym == SDLK_w) {
        printf("w was pressed in App.cpp\n");
    }
}
