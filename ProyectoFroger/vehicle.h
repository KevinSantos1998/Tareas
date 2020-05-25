
#ifndef vehicle_h
#define vehicle_h

#include <SDL.h>
#include "gameObject.h"

class Vehicle: public GameObject
{
public:
    Vehicle(int fwidth = 50, int fheight = 50, int nframes = 4, int nsprites = 1);

    bool active;

    void reset();
    void moveSprite();
};

#endif // vehicle_h
