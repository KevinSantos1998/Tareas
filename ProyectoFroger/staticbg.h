
#ifndef staticbg_h
#define staticbg_h

#include <SDL.h>
#include "header.h"


class StaticBG
{
protected:
    SDL_Texture *background;

    SDL_Rect image;
    SDL_Rect screen;

public:
    StaticBG(int x = 0, int y = 0, int width = STATICBG_WIDTH, int height = STATICBG_HEIGHT);

    bool loadBG(SDL_Renderer *renderer, char *filename);
    void bgRender(SDL_Renderer *renderer, int y);

#endif //scrollbg_h
