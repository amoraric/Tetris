#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Shape.h"
#include "Position.h"
/**
 * @file Board.h
 * @brief The Board class represents the container where the bricks fall
 */
class Board {
    /**
     * @brief board_ The board is represented by a 2d vector of booleans
     */
    std::vector<std::vector<bool>> board_;
public:
    /**
     * @brief Board Constructor of the board
     * @param rows Number of rows
     * @param columns Number of columns
     */
    Board(int rows, int columns); // the user can ajust the side of the board
    /**
     * @brief isInside Checks if a position is inside the board
     * @param position The position to check
     * @return True if the position is inside the board, false if not
     */
    bool isInside(Position position); // is the element inside the board so that it doesn't go out
    /**
     * @brief clearLines clear the lines of the board
     */
    void clearLines();
    std::vector<int> getCompletedLines();
    void placeBrick(const Shape& shape, Position pos); // solidify the brick
    bool isOccupied(Position pos) const;
};

#endif // BOARD_H
