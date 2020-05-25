
#include <SDL.h>
#include <fstream>

#include "header.h"
#include "scrollbg.h"


ScrollBG::ScrollBG(SDL_Color color, int x, int y, int width, int height):
        StaticBG(x, y, width, height)
{

    image = {width - SCREEN_WIDTH, 0, SCREEN_WIDTH, height};


    screen = {x, y, SCREEN_WIDTH, height};

    offset = {width, 0, 0, height};

    offsetScreen = {x, y, 0, height};

    bgColor = color;
}

bool ScrollBG::bgScroll(int dx)
{

    if (dx > 0 && image.x <= 0)
    {

        offset.x -= dx;

        offset.w += dx;
        offsetScreen.w += dx;

        image.w -= dx;
        screen.x += dx;
        screen.w -= dx;

        if (offset.w >= SCREEN_WIDTH)
        {
            screen.x = 0;
            screen.w = SCREEN_WIDTH;

            image.x = SCROLLBG_WIDTH - SCREEN_WIDTH;
            image.w = SCREEN_WIDTH;

            offsetScreen.w = 0;
            offset.w = 0;
            offset.x = SCROLLBG_WIDTH;

            return true;
        }

    } else {
        image.x += dx;
    }

    return false;
}

void ScrollBG::bgRender(SDL_Renderer *renderer, int y)
{
    screen.y = y;
    offsetScreen.y = y;

    SDL_SetTextureBlendMode(background, SDL_BLENDMODE_BLEND);

    SDL_SetTextureAlphaMod(background, bgColor.a);

    SDL_SetTextureColorMod(background, bgColor.r, bgColor.g, bgColor.b);

    SDL_RenderCopy(renderer, background, &image, &screen);
    SDL_RenderCopy(renderer, background, &offset, &offsetScreen);
}
