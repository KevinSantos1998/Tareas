
#include <SDL.h>
#include <fstream>
#include <cstdlib>

#include "header.h"
#include "sprite.h"

Sprite::Sprite(int fwidth, int fheight, int nframes, int nsprites)
{

    animCounter = 0;
    rotation = 0;
    alpha = 255;
    frameWidth = fwidth;
    frameHeight = fheight;
    numFrames = nframes;
    numSprites = nsprites;
    image = {0, 0, fwidth, fheight};
    screen = {0, 350, fwidth, fheight};
}

int Sprite::getY()
{
    return screen.y;
}

int Sprite::getX()
{
    return screen.x;
}


void Sprite::randomSprite()
{
    image.y = rand()%numSprites * frameHeight;
}

void Sprite::selectSprite(int spriteNum)
{
    image.y = (spriteNum - 1) * frameHeight;
}

void Sprite::rotateSprite(int newAngle)
{
    rotation = newAngle;
}

void Sprite::animate()
{
    if (animCounter >= ANIMATION_SPEED)
    {
        image.x = ( image.x >= frameWidth * (numFrames - 1) ) ? 0 : image.x + frameWidth;

        animCounter = 0;
    } else {
        animCounter ++;
    }
}

void Sprite::setSprite(int fwidth, int fheight, int nframes, int nsprites)
{
    frameWidth = fwidth;
    frameHeight = fheight;
    numFrames = nframes;
    numSprites = nsprites;
    image = {0, 0, fwidth, fheight};
    screen = {0, 350, fwidth, fheight};
}


bool Sprite::loadSprite(SDL_Renderer *renderer, char* filename)
{

    SDL_Surface *temp;
    temp = SDL_LoadBMP(filename);

    if (temp == NULL)
    {
        fprintf(stderr, "Couldn't load %s: %s", filename, SDL_GetError());
        return false;
    }

    SDL_SetColorKey(temp, SDL_TRUE, SDL_MapRGB(temp->format,250,250,250));

    spriteSheet = SDL_CreateTextureFromSurface(renderer, temp);

    if (!spriteSheet)
    {
        fprintf(stderr, "Couldn't create texture: %s\n", SDL_GetError());
        SDL_FreeSurface(temp);
        return false;
    }

    SDL_FreeSurface(temp);

    return true;
}

void Sprite::render(SDL_Renderer *renderer)
{
    SDL_SetTextureAlphaMod(spriteSheet, alpha);
    SDL_RenderCopyEx(renderer, spriteSheet, &image, &screen, rotation, NULL, SDL_FLIP_NONE);
}
