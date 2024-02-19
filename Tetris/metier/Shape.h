#ifndef SHAPE_H
#define SHAPE_H

#include <vector>

#include "Position.h"

class Position;

/**
 * @brief The Shape struct represents a shape used in the game.
 */
struct Shape {
    std::vector<Position> shape; /**< The positions that make up the shape. */
};

#endif // SHAPE_H
