#include <SDL.h>

class Sprite{
    public:
        Sprite(int x, int y, int width, int height);
        virtual ~Sprite();
        /**
        * Update the sprite & all sub-components
        * @param deltaTime milliseconds passed since the last update
        */
        virtual void update(Uint32 deltaTime){}

        /**
        * Draw the Sprite & all sub-components
        * @param renderer Use it for all your SDL rendering needs (don't render this to the screen)
        */
        virtual void draw(SDL_Renderer* renderer){}

    protected:
        /**
        * Basic properties showing the position & size of this objects.
        **/
        int x;
        int y;
        int width;
        int height;

        /**
        * Shortcut for a Collision Group of 0b0000
        */
        bool isGhost;

        /**
        * Collision Group represents the group that this Sprite collides with.
        * 0b0000 will collide with nothing
        * 0b0001 will collide with all other 0b0001 objects & so on.
        */
        short collisionGroup;
};
