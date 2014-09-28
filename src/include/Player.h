#ifndef _PLAYER_H_
    #define _PLAYER_H_
#include "Sprite.h"

class Player : protected Sprite {
    public:
        Player(int x, int y);
        ~Player();
        void moveLeft();
        void moveRight();
};
#endif // _PLAYER_H_
