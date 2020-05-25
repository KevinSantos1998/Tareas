
#ifndef watervehicle_h
#define watervehicle_h

#include <SDL.h>
#include "gameObject.h"

class WaterVehicle: public GameObject
{
private:
    bool isBoat;

public:
    WaterVehicle(bool isABoat = false, int fwidth = 50, int fheight = 50, int nframes = 4, int nsprites = 1);

    void moveSprite();
};

#endif // watervehicle_h
