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
    static const Direction LEFT;
    static const Direction DOWN;
    static const Direction RIGHT;
    int getDx() const;
    int getDy() const;
};

#endif // DIRECTION_H
