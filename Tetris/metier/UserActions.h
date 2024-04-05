#ifndef USERACTIONS_H
#define USERACTIONS_H

/**
 * @brief The UserActions enum class defines the possible actions that a user can take in the game.
 */
enum class UserActions
{
    RIGHT, /**< Move the current brick to the right. */
    LEFT, /**< Move the current brick to the left. */
    DOWN, /**< Move the current brick down. */
    PAUSE, /**< Pause the game. */
    DROP, /**< Drop the current brick to the lowest possible position. */
    ROTATE_RIGHT, /**< Rotate the current brick clockwise. */
    ROTATE_LEFT /**< Rotate the current brick counterclockwise. */
};

#endif // USERACTIONS_H
