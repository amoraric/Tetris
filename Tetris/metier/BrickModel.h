#ifndef BRICKMODEL_H
#define BRICKMODEL_H

#include <vector>

#include "Position.h"

class Position;

/**
 * @brief The Shape struct represents a shape used in the game.
 */
struct BrickModel {
    std::vector<Position> model; /**< The positions that make up the shape. */
    /**
     * @brief Equality operator for BrickModel.
     * @param other The other BrickModel to compare with.
     * @return True if the models are equal, false otherwise.
     */
    bool operator==(const BrickModel& other) const;
};

#endif // BRICKMODEL_H
