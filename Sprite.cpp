#include "Sprite.h"

Sprite::Sprite(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;

    isGhost = false;
    collisionGroup = 0x0000;
    collisionMask = 0x0000;
}

Sprite::~Sprite(){}




