
#ifndef frog_h
#define frog_h

#include "gameObject.h"


class Frog: public GameObject
{
protected:

    bool inMotion;

    int destX, destY;

    double dx, dy;


public:
    static bool occupied[4];

    Frog(int fwidth = 50, int fheight = 50, int nframes = 4, int nsprites = 1);

    bool onUpperLog, onLowerLog, onBoat;

    void setDest(int x, int y);
    void setOccupied(int i);

    int getDestX();
    int getDestY();
    bool isInMotion();
    bool isOccupied(int i);
    bool allPadsOccupied();

    void setMotion(double motionx, double motiony);

    void moveFrog();

    void reset();

    void resetPads();

};


#endif
