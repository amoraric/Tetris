#ifndef BRICK_H
#define BRICK_H

#include <memory>

#include "BrickState.h"

class Position;
class Shape;
class Board;
class Direction;

class Brick {
    int orientation_;
    std::unique_ptr<Shape> shape_;
    std::unique_ptr<Position> upperLeft_;
    BrickState state_;
public:
    Brick(Shape s);
    void translation(Direction direction);
    void rotation(bool clockwise);
    bool canMove(const Board& board, int dx, int dy) const;
    bool canRotate(const Board& board) const;
    BrickState getBrickState();
    std::unique_ptr<Position> getUpperLeft();
    std::unique_ptr<Shape> getShape();
};

#endif // BRICK_H
