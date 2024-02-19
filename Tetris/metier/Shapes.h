#ifndef SHAPES_H
#define SHAPES_H

#include <vector>

class Position;
class Shape;

class Shapes {
    std::vector<Shape> shapes_;
public:
    Shapes();
    bool addShape(const Shape& newShape); // check if the shape is appropriate for the game (4x4 max, etc.)
    static const Shape T;
    static const Shape L;
    static const Shape I;
    static const Shape J;
    static const Shape Z;
    static const Shape S;
    static const Shape O;
};


#endif // SHAPES_H
