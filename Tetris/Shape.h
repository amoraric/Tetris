#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <string>
#include "Position.h"

class Shape {
    std::vector<Position> shapePositions;
public:
    Shape(std::vector<Position> shapePositions);
    static const Shape T;
    static const Shape L;
    static const Shape I;
    static const Shape J;
    static const Shape Z;
    static const Shape S;
    static const Shape O;
};


#endif // SHAPE_H
