
#include <SDL.h>
#include <fstream>

#include "header.h"
#include "staticbg.h"

StaticBG::StaticBG(int x, int y, int width, int height)
{
    image = {0, 0, width, height};

    screen = {x, y, width, height};
}

bool StaticBG::loadBG(SDL_Renderer *renderer, char *filename)
{

    SDL_Surface *temp;
    temp = SDL_LoadBMP(filename);

    if (temp == NULL)
    {
        fprintf(stderr, "Couldn't load %s: %s", filename, SDL_GetError());
        return false;
    }

    background = SDL_CreateTextureFromSurface(renderer, temp);

    if (!background)
    {
        fprintf(stderr, "Couldn't create texture: %s\n", SDL_GetError());
        SDL_FreeSurface(temp);
        return false;
    }

    SDL_FreeSurface(temp);

    return true;
}

void StaticBG::bgRender(SDL_Renderer *renderer, int y)
{
    screen.y = y;
    SDL_RenderCopy(renderer, background, &image, &screen);
}
