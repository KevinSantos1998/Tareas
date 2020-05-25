
#ifndef gameObject_h
#define gameObject_h

#include "sprite.h"


class GameObject: public Sprite
{
protected:

    double posX, posY;

public:

    GameObject(int fwidth = 50, int fheight = 50, int nframes = 4, int nsprites = 1);

    void setPosition(int x, int y);
    void randomPosition(int minX, int maxX, int minY, int maxY, int stepX, int stepY);

    void translate(double dx, double dy);

    void moveSprite(){};

};

#endif
