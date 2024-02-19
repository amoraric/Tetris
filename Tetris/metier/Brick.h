#ifndef BRICK_H
#define BRICK_H

#include <memory>
#include "BrickState.h"
#include "Position.h"
#include "Shape.h"
#include "Board.h"
#include "Direction.h"

/**
 * @brief The Brick class represents a brick notably the current brick used in the game
 */
class Brick {
    /**
     * @brief orientation_ represents the orientation of the brick
     */
    int orientation_;
    /**
     * @brief shape_ The shape of the brick
     */
    std::unique_ptr<Shape> shape_;
    /**
     * @brief upperLeft_ The upperLeft point of the brick
     */
    std::unique_ptr<Position> upperLeft_;
    /**
     * @brief state_ Current state of the brick
     */
    BrickState state_;
public:
    /**
     * @brief Brick
     * @param s
     */
    Brick(Shape s);
    /**
     * @brief Moves the brick to the left, right or down
     * @param direction The direction to move the brick to
     */
    void translation(Direction direction);
    /**
     * @brief Rotates the brick clockwise or counterclockwise
     * @param clockwise If set at true rotates the brick clockwise
     */
    void rotation(bool clockwise);
    bool canMove(const Board& board, int dx, int dy) const;
    bool canRotate(const Board& board) const;
    BrickState getBrickState();
    std::unique_ptr<Position> getUpperLeft();
    std::unique_ptr<Shape> getShape();
};

#endif // BRICK_H
