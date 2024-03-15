#ifndef BRICKSTATE_H
#define BRICKSTATE_H

/**
 * @brief Enumerates the possible states a brick can be in.
 */
enum class BrickState {
    FREE, /**< The brick is free to move. */
    BLOCKED, /**< The brick is blocked and cannot move further. */
    ACCOMPLISHED, /**< The brick has accomplished its goal. */
    FALLING
};

#endif // BRICKSTATE_H
