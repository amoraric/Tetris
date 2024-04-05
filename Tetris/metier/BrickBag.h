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
    /**
     * @brief getBrickBag
     * @return
     */
    std::vector<BrickModel> getBrickBag();
    /**
     * @brief eraseBrickIndex
     * @param index
     */
    void eraseBrickIndex(int index);
};

/**
 * @brief Namespace containing predefined static shapes.
 */
namespace StaticBrickModels {
    const BrickModel T {{ {0, 1}, {1, 0}, {1, 1}, {1, 2} }}; /**< T shape. */
    const BrickModel L {{ {0, 0}, {1, 0}, {2, 0}, {2, 1} }}; /**< L shape. */
    const BrickModel I {{ {0, 0}, {1, 0}, {2, 0}, {3, 0} }}; /**< I shape. */
    const BrickModel J {{ {0, 1}, {1, 1}, {2, 1}, {2, 0} }}; /**< J shape. */
    const BrickModel Z {{ {0, 0}, {0, 1}, {1, 1}, {1, 2} }}; /**< Z shape. */
    const BrickModel S {{ {0, 1}, {0, 2}, {1, 0}, {1, 1} }}; /**< S shape. */
    const BrickModel O {{ {0, 0}, {1, 0}, {0, 1}, {1, 1} }}; /**< O shape. */
}

#endif // BRICKBAG_H
