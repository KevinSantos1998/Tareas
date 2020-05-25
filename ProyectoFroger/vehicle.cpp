
#include <SDL.h>

#include "header.h"
#include "vehicle.h"

Vehicle::Vehicle(int fwidth, int fheight, int nframes, int nsprites):
    GameObject(fwidth, fheight, nframes, nsprites)
{
    reset();
}

void Vehicle::reset()
{
    randomSprite();
    randomPosition(0, 0, 350, 490, 50, 50);
    rotation = (screen.y == 400) ? 180 : 0;
    screen.x = (screen.y == 400) ? SCREEN_WIDTH : -image.w;
}

void Vehicle::moveSprite()
{
    if (screen.y == 350) {
        translate(FAST_VEHICLE_SPEED, 0);
        if (screen.x > SCREEN_WIDTH){
            reset();
            active = false;
        }
    } else if (screen.y == 400) {
        translate(-1 * VEHICLE_SPEED, 0);
        if (screen.x < -image.w){
            reset();
            active = false;
        }
    } else {
        translate(VEHICLE_SPEED, 0);
        if (screen.x > SCREEN_WIDTH){
            reset();
            active = false;
        }
    }
}
