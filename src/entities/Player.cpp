#include <stdio.h>
#include "../include/Player.h"
SDL_Rect body;
Player::Player(int x, int y) : Sprite(x, y, 32, 64) {
    body = {x, y, 32, 64};
}

Player::~Player() {

}

bool isMoveHor  = false;
bool isMoveVert = false;
void Player::moveLeft() {
    isMoveHor = true;
    dx = -1.0f;
}

void Player::moveRight() {
    isMoveHor = true;
    dx = 1.0f;
}

void Player::moveUp() {
    isMoveVert = true;
    dy = -1.0f;
}

void Player::moveDown() {
    isMoveVert = true;
    dy = 1.0f;
}

void Player::stopMovingHorizontal() {
    isMoveHor = false;
}


void Player::stopMovingVertical() {
    isMoveVert = false;
}

void Player::jump() {
    dy = -1.0f;
}

void Player::update(Uint32 deltaTime) {
    Sprite::update(deltaTime);
    x += dx * 10;
    y += dy * 10;
    body.x = x;
    body.y = y;

    if (!isMoveHor) {
        dx = 0.0f;
    }

    if (!isMoveVert) {
        dy = 0.0f;
    }
}

void Player::draw(SDL_Renderer* renderer) {
    Sprite::draw(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
    SDL_RenderDrawLine(renderer, x - 5, y - 10, x + 5, y - 10);
    SDL_RenderDrawLine(renderer, x - 5, y - 10, x, y + 10);
    SDL_RenderDrawLine(renderer, x, y + 10, x + 5, y - 10);
}
