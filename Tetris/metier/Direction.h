#ifndef DIRECTION_H
#define DIRECTION_H

/**
 * @brief This class defines a Direction
 */
class Direction {
    /**
     * @brief dx_ The horizontal direction
     */
    int dx_;
    /**
     * @brief dy_ The vertical direction
     */
    int dy_;

public:
    /**
     * @brief Direction Constructor of a direction
     * @param x The horizontal direction
     * @param y The vertical direction
     */
    Direction(int x, int y);
    /**
     * @brief Represents the left direction.
     */
    static const Direction LEFT;
    /**
     * @brief Represents the down direction.
     */
    static const Direction DOWN;
    /**
     * @brief Represents the right direction.
     */
    static const Direction RIGHT;
    /**
     * @brief Gets the horizontal component of the direction.
     * @return The horizontal component.
     */
    int getDx() const;
    /**
     * @brief Gets the vertical component of the direction.
     * @return The vertical component.
     */
    int getDy() const;
};

#endif // DIRECTION_H
