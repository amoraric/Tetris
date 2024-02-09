#ifndef DIRECTION_H
#define DIRECTION_H

#include "Position.h"

class Direction {
    Position coordinates_;
    Direction(int x, int y);

public:
    static const Direction LEFT;
    static const Direction DOWN;
    static const Direction RIGHT;

// getter?
};

#endif // DIRECTION_H
