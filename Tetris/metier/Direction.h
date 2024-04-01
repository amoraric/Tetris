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
     * @brief Gets the horizontal component of the direction.
     * @return The horizontal component.
     */
    int getDx() const;
    /**
     * @brief Gets the vertical component of the direction.
     * @return The vertical component.
     */
    int getDy() const;
    bool operator==(const Direction& other) const;
};



/**
 * @brief Namespace containing static Directions.
 */
namespace StaticDirections {
    extern const Direction LEFT ;
    extern const Direction DOWN;
    extern const Direction RIGHT;
}

#endif // DIRECTION_H
