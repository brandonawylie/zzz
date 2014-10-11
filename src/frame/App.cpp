#include <stdio.h>
#include <SDL.h>
#include <windows.h>
#include "../include/App.h"
#include "../include/Player.h"


App::App(SDL_Window* window) {
    this->window = window;

}

App::~App() {

}
Player *player;
void App::init() {
    player = new Player(0,0);
}

void App::cleanup() {

}

bool App::update(Uint32 dt){
    player->update(dt);
    Sleep(20);
    return false;
}

void App::draw(SDL_Renderer* renderer) {
    player->draw(renderer);
}

void App::onEvent(SDL_Event* event) {
    EventListener::onEvent(event);
}

void App::onKeyDown(SDL_Keycode sym) {
    if (sym == SDLK_w) {
        player->moveUp();
    }

    if (sym == SDLK_s) {
       player->moveDown();
    }

    if (sym == SDLK_a) {
        player->moveLeft();
    }

    if (sym == SDLK_d) {
        player->moveRight();
    }

}

void App::onKeyUp(SDL_Keycode sym){
    if (sym == SDLK_w) {
        player->stopMovingVertical();
    }

    if (sym == SDLK_s) {
        player->stopMovingVertical();
    }

    if (sym == SDLK_a) {
        player->stopMovingHorizontal();
    }

    if (sym == SDLK_d) {
        player->stopMovingHorizontal();
    }
}
