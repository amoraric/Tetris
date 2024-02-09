#ifndef BRICK_H
#define BRICK_H

#include "Position.h"

class Brick {
    int orientation_;
    Position upperLeft_;
    // shape
public:
    // constructor
    void translation();
    void rotation();

};

#endif // BRICK_H
