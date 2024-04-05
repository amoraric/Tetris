#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "BrickModel.h"
#include "Position.h"

class BrickModel;
class Position;

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
    Board(std::size_t rows, std::size_t columns); // the user can ajust the side of the board
    /**
     * @brief isInside Checks if a position is inside the board
     * @param position The position to check
     * @return True if the position is inside the board, false if not
     */
    bool isInside(Position position); // is the element inside the board so that it doesn't go out
    /**
     * @brief clearLines clears the lines of the board
     */
    void clearLines(std::vector<int> completedLines);
    /**
     * @brief getCompletedLines Gets the indices of completed lines
     * @return A vector containing the indices of completed lines
     */
    std::vector<int> getCompletedLines();
    /**
     * @brief placeBrick Places a brick on the board
     * @param shape The model of the brick
     * @param pos The position to place the brick
     */
    void placeBrick(const BrickModel& brickModel, Position pos);
    /**
     * @brief isOccupied Checks if a position on the board is occupied
     * @param pos The position to check
     * @return True if the position is occupied, false otherwise
     */
    bool isOccupied(Position pos) const;
    /**
     * TODO
     */
    int getSize();
    std::vector<std::vector<bool>> getBoard();
    void randomize();
};

#endif // BOARD_H
