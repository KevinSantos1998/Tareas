
#ifndef scrollbg_h
#define scrollbg_h

#include <SDL.h>
#include "staticbg.h"
#include "header.h"


class ScrollBG: public StaticBG
{
protected:
    SDL_Rect offset;
    SDL_Rect offsetScreen;

public:
    ScrollBG(SDL_Color color = {255, 255, 255, 255}, int x = 0, int y = 0, int width = SCROLLBG_WIDTH, int height = SCROLLBG_HEIGHT);
    SDL_Color bgColor;

    bool bgScroll(int dx);
    void bgRender(SDL_Renderer *renderer, int y);
};

#endif //scrollbg_h
