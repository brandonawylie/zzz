#include "../include/Sprite.h"
#include <windows.h>

Sprite::Sprite(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;

    this->isGhost = false;
    this->collisionGroup = 0;
    this->collisionMask = 0;
}

Sprite::Sprite(int x, int y, int width, int height, bool isGhost, short collisionGroup, short collisionMask) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;

    this->isGhost = isGhost;
    this->collisionGroup = collisionGroup;
    this->collisionMask = collisionMask;
}

Sprite::~Sprite(){}

void Sprite::update(Uint32 deltaTime) {

}

void Sprite::draw(SDL_Renderer* renderer) {

}




