#ifndef _SPRITE_H_
    #define _SPRITE_H_

#include <SDL.h>

class Sprite{
    public:
        Sprite(int x, int y, int width, int height);
        Sprite(int x, int y, int width, int height, bool isGhost, short collisionGroup, short collisionMask);
        virtual ~Sprite();

        /**
        * Update the sprite & all sub-components
        * @param deltaTime milliseconds passed since the last update
        */
        virtual void update(Uint32 deltaTime);

        /**
        * Draw the Sprite & all sub-components
        * @param renderer Use it for all your SDL rendering needs (don't render this to the screen)
        */
        virtual void draw(SDL_Renderer* renderer);

        /**
        * Get the X position of this sprite
        * @return X position of this sprite
        */
        int getX(){return x;}
        /**
        * Get the Y position of this sprite
        * @return Y position of this sprite
        */
        int getY(){return y;}
        /**
        * Sets the X position of this sprite
        * @param X coordinate to set
        */
        void setX(int x){this->x = x;}
        /**
        * Sets the Y position of this sprite
        * @param Y coordinate to set
        */
        void setY(int y){this->y = y;}

        /**
        * Get the width of this sprite
        * @return width of this sprite
        */
        int getWidth(){return width;}
        /**
        * Get the height of this sprite
        * @return height of this sprite
        */
        int getHeight(){return height;}
        /**
        * Sets the width of this sprite
        * @param width to set
        */
        void setWidth(int width){this->width = width;}
        /**
        * Sets the height of this sprite
        * @param height to set
        */
        void setHeight(int height){this->height = height;}


        /**
        * Gets the ghost status of this sprite. A ghost is a sprite that ignores collision
        * and gravity, but still sends events when it collides with something.
        * @return bool indicating ghost status
        */
        bool GetIsGhost(){return isGhost;}
        /**
        * Sets the ghost status of this sprite. A ghost is a sprite that ignores collision
        * and gravity, but still sends events when it collides with something.
        * @param bool indicating ghost status
        */
        void setIsGhost(bool isGhost){this->isGhost = isGhost;}

        /**
        * Gets the collision group of this sprite
        * @return the sprite's collision group
        */
        short getCollisionGroup(){return collisionGroup;}
        /**
        * Gets the collision mask of this sprite
        * @return the sprite's collision mask
        */
        short getCollisionMask(){return collisionMask;}
        /**
        * Sets the collision group of this sprite
        * @param the sprite's collision group
        */
        void setCollisionGroup(short collisionGroup){this->collisionGroup = collisionGroup;}
        /**
        * Sets the collision mask of this sprite
        * @param the sprite's collision mask
        */
        void setCollisionMask(short collisionMask){this->collisionMask = collisionMask;}

    protected:
        /**
        * Basic properties showing the position & size of this objects.
        **/
        int x;
        int y;
        int width;
        int height;
        float dx;
        float dy;
        float speed;

        /**
        * Shortcut for a Collision Group of 0b0000
        */
        bool isGhost;

        /**
        * Collision Group represents the group that this Sprite belongs to
        */
        short collisionGroup;

        /**
        * Collision Mask is a bit mask for the collision group to see what other groups it collides with.
        */
        short collisionMask;
};
#endif // _SPRITE_H_
