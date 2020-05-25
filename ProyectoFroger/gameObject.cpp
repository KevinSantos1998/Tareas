
#include <SDL.h>
#include <cstdlib>

#include "gameObject.h"

GameObject::GameObject(int fwidth, int fheight, int nframes, int nsprites):
    Sprite(fwidth, fheight, nframes, nsprites)
{
    posX = screen.x;
    posY = screen.y;
}


void GameObject::translate(double dx, double dy)
{
    posX += dx;
    posY += dy;

    screen.x = posX;
    screen.y = posY;
}

void GameObject::setPosition(int x, int y)
{
    posX = x;
    posY = y;

    screen.x = posX;
    screen.y = posY;
}


void GameObject::randomPosition(int minX, int maxX, int minY, int maxY, int stepX, int stepY)
{
    screen.x = ((rand()%((maxX+1)-minX) + minX)/(stepX)) * stepX;
    screen.y = ((rand()%((maxY+1)-minY) + minY)/(stepY)) * stepY;

    posX = screen.x;
    posY = screen.y;
}
