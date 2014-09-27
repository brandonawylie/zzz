#include "App.h"
#include <stdio.h>
#include <SDL.h>

App::App(SDL_Window* window) {
    this->window = window;

}

App::~App() {

}
SDL_Rect playerEx;
void App::init() {
    playerEx = {50, 50, 64, 64};
}

void App::cleanup() {

}

bool App::update(Uint32 dt){
    return false;
}

void App::draw(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 100, 100, 255);
    SDL_RenderFillRect(renderer, &playerEx);
}

void App::onEvent(SDL_Event* event) {
    EventListener::onEvent(event);
}

void App::onKeyDown(SDL_Keycode sym) {

    if (sym == SDLK_w) {
        playerEx.y++;
    }

    if (sym == SDLK_s) {
        playerEx.y--;
    }

    if (sym == SDLK_a) {
        playerEx.x--;
    }

    if (sym == SDLK_d) {
        playerEx.x++;
    }
}
