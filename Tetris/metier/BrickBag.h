#ifndef BRICKBAG_H
#define BRICKBAG_H

#include <vector>

#include "BrickModel.h"

class BrickModel;

/**
 * @brief The Shapes class manages the shapes available in the game.
 */
class BrickBag {
    std::vector<BrickModel> brickBag_; /**< The list of shapes available. */
public:
    /**
     * @brief Constructor for the Shapes class.
     */
    BrickBag();
    /**
     * @brief Adds a new shape to the list of available shapes and checks if it is appropriate.
     * @param newShape The shape to add.
     * @return True if the shape is added successfully, false otherwise.
     */
    bool addBrick(const BrickModel& newBrick);
};

/**
 * @brief Namespace containing predefined static shapes.
 */
namespace StaticBrickModels {
    extern const BrickModel T; /**< T shape. */
    extern const BrickModel L; /**< L shape. */
    extern const BrickModel I; /**< I shape. */
    extern const BrickModel J; /**< J shape. */
    extern const BrickModel Z; /**< Z shape. */
    extern const BrickModel S; /**< S shape. */
    extern const BrickModel O; /**< O shape. */
}
#endif // BRICKBAG_H
