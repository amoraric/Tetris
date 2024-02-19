#ifndef BRICK_H
#define BRICK_H

#include <memory>
#include "BrickState.h"
#include "Position.h"
#include "Shape.h"
#include "Board.h"
#include "Direction.h"

class Position;
class Shape;
class Board;
class Direction;

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
    /**
     * @brief Checks if the brick can move in the specified direction.
     * @param board The game board.
     * @param dx The change in x-coordinate.
     * @param dy The change in y-coordinate.
     * @return True if the brick can move, false otherwise.
     */
    bool canMove(const Board& board, int dx, int dy) const;
    /**
     * @brief Checks if the brick can rotate.
     * @param board The game board.
     * @return True if the brick can rotate, false otherwise.
     */
    bool canRotate(const Board& board) const;
    /**
     * @brief Gets the state of the brick.
     * @return The state of the brick.
     */
    BrickState getBrickState();
    /**
     * @brief Gets the upper-left position of the brick.
     * @return A unique pointer to the upper-left position of the brick.
     */
    std::unique_ptr<Position> getUpperLeft();
    /**
     * @brief Gets the shape of the brick.
     * @return A unique pointer to the shape of the brick.
     */
    std::unique_ptr<Shape> getShape();
};

#endif // BRICK_H
