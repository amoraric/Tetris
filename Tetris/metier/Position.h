#ifndef POSITION_H
#define POSITION_H

#include <utility>

/**
 * @brief The Position class represents a position on the game board.
 */
class Position {
    std::pair<int, int> coordinates_; /**< The coordinates of the position. */

public:
    /**
     * @brief Constructor for the Position class.
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     */
    Position(int x, int y);
    /**
     * @brief Gets the x-coordinate of the position.
     * @return The x-coordinate.
     */
    int get_x() const;
    /**
     * @brief Gets the y-coordinate of the position.
     * @return The y-coordinate.
     */
    int get_y() const;
    /**
     * @brief Overloaded equality operator to compare two positions.
     * @param other The other position to compare.
     * @return True if the positions are equal, false otherwise.
     */
    bool operator==(const Position& other) const;
};

/**
 * @brief Compares two positions for equality.
 * @param pos1 The first position to compare.
 * @param pos2 The second position to compare.
 * @return True if the positions are equal, false otherwise.
 */
bool comparePositions(const Position &pos1, const Position &pos2);

#endif // POSITION_H
