
#ifndef sprite_h
#define sprite_h

#include <SDL.h>

class Sprite
{
protected:
    SDL_Texture *spriteSheet;

    int frameWidth, frameHeight, numFrames, numSprites;

    int rotation, alpha;

    int animCounter;

    SDL_Rect image;
    SDL_Rect screen;

public:

    Sprite(int fwidth = 50, int fheight = 50, int nframes = 4, int nsprites = 1);

    bool loadSprite(SDL_Renderer *renderer, char *filename);

    void setSprite(int fwidth, int fheight, int nframes, int nsprites);
    void setAlpha(int a);
    void rotateSprite(int newAngle);
    void selectSprite(int spriteNum);
    void randomSprite();

    int getY();
    int getX();
    int getAlpha();

    void animate();

    void render(SDL_Renderer *renderer);

    virtual void moveSprite() = 0;
};

#endif // sprite_h
