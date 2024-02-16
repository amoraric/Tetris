#ifndef BRICK_H
#define BRICK_H

#include "Position.h"
#include "Shape.h"

class Brick {
    int orientation_;
    Shape s_;
    Position upperLeft_;
public:
    Brick(Shape s);
    void translation();
    void rotation();    
};

#endif // BRICK_H
