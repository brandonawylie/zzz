#ifndef _PLAYER_H_
    #define _PLAYER_H_
#include "Sprite.h"

class Player : protected Sprite {
    public:
        Player(int x, int y);
        ~Player();

        /**
        * Move the player left
        */
        void moveLeft();
        /**
        * Move the player right
        */
        void moveRight();

        /**
        * Make the player jump
        */
        void jump();

        /**
        * Update the sprite & all sub-components
        * @param deltaTime milliseconds passed since the last update
        */
        void update(Uint32 deltaTime);

        /**
        * Draw the Sprite & all sub-components
        * @param renderer Use it for all your SDL rendering needs (don't render this to the screen)
        */
        void draw(SDL_Renderer* renderer);
};
#endif // _PLAYER_H_
