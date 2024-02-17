#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Shape;
class Position;

class Board {
    std::vector<std::vector<bool>> board_;
public:
    Board();
    bool isInside(Position position); // is the element inside the board so that it doesn't go out
    void clearLines();
    std::vector<int> getCompletedLines();
    void placeBrick(const Shape& shape, Position pos); // solidify the brick
    bool isOccupied(Position pos) const;
};

#endif // BOARD_H
