#include <stdio.h>
#include "../include/Player.h"
SDL_Rect body;
Player::Player(int x, int y) : Sprite(x, y, 32, 64) {
    body = {x, y, 32, 64};
}

Player::~Player() {

}

bool isMove = false;
void Player::moveLeft() {
    isMove = true;
    dx = -1.0f;
}

void Player::moveRight() {
    isMove = true;
    dx = 1.0f;
}

void Player::stopMoving() {
    isMove = false;
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

    if (!isMove) {
        dx = 0;
    }
}

void Player::draw(SDL_Renderer* renderer) {
    Sprite::draw(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
    SDL_RenderFillRect(renderer, &body);
}
