
#include <SDL.h>

#include "frog.h"
#include "header.h"


bool Frog::occupied[4] = {false, false, false, false};


Frog::Frog(int fwidth, int fheight, int nframes, int nsprites):
    GameObject(fwidth, fheight, nframes, nsprites)
{
    inMotion = false;
    dx = 0;
    dy = 0;
    destX = 0;
    destY = 0;
    onUpperLog = false;
    onLowerLog = false;
    onBoat = false;

    reset();
}

void Frog::moveFrog()
{

    translate(dx, dy);
    if (getX() < 0) {

        setPosition(0, getY());
        inMotion = false;
    }
    if (getX() > SCREEN_WIDTH - 50) {

        setPosition(SCREEN_WIDTH - 50, getY());
        inMotion = false;
    }
    if (getY() < 150)
    {

        inMotion = false;
        for (int i = 0; i < 4; i++)
        {

            if (getX() + 20 > 100 + i * 200 && getX() + 40 < 100 + i * 200 + 50 && occupied[i] == false) inMotion = true;
        }
        if (inMotion == false) setPosition(getX(), 150);
    }


    if (dx > 0 && getX() >= destX) inMotion = false;
    if (dx < 0 && getX() <= destX) inMotion = false;
    if (dy != 0 && getY() == destY) inMotion = false;
    if (inMotion == false) selectSprite(1);
}


void Frog::setDest(int x, int y)
{
    destX = x;
    destY = y;
}

int Frog::getDestX()
{
    return destX;
}


void Frog::setMotion(double motionx, double motiony)
{

    dx = motionx;
    dy = motiony;

    inMotion = true;

    selectSprite(2);
}

void Frog::reset()
{
    setSprite(50, 50, 4, 2);
    setPosition(350, 500);
    setAlpha(255);
    inMotion = false;
    rotation = 0;
}

void Frog::resetPads()
{
    for (int i = 0; i < 4; i++) occupied[i] = false;
}


bool Frog::Occupied(int i)
{
    return occupied[i];
}


bool Frog::PadsOccupied()
{
    bool check = true;
    for (int i = 0; i < 4; i++) if (occupied[i]==false) check = false;
    return check;
}
