#ifndef SHAPES_H
#define SHAPES_H

#include <vector>

#include "Shape.h"

class Shape;

/**
 * @brief The Shapes class manages the shapes available in the game.
 */
class Shapes {
    std::vector<Shape> shapes_; /**< The list of shapes available. */
public:
    /**
     * @brief Constructor for the Shapes class.
     */
    Shapes();
    /**
     * @brief Adds a new shape to the list of available shapes and checks if it is appropriate.
     * @param newShape The shape to add.
     * @return True if the shape is added successfully, false otherwise.
     */
    bool addShape(const Shape& newShape);
};

/**
 * @brief Namespace containing predefined static shapes.
 */
namespace StaticShapes {
    extern const Shape T; /**< T shape. */
    extern const Shape L; /**< L shape. */
    extern const Shape I; /**< I shape. */
    extern const Shape J; /**< J shape. */
    extern const Shape Z; /**< Z shape. */
    extern const Shape S; /**< S shape. */
    extern const Shape O; /**< O shape. */
}
#endif // SHAPES_H
