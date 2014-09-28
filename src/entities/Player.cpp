#include "../include/Player.h"
Player::Player(int x, int y) : Sprite(x, y, 32, 64) {

}

Player::~Player() {

}

void Player::moveLeft() {
    dx = -1.0f;
}

void Player::moveRight() {
    dx = 1.0f;
}

void Player::jump() {
    dy = -1.0f;
}

void Player::update(Uint32 deltaTime) {
    Sprite::update(deltaTime);
}

void Player::draw(SDL_Renderer* renderer) {
    Sprite::draw(renderer);
}
