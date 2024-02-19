#ifndef GAMESTATE_H
#define GAMESTATE_H

/**
 * @brief Enumerates the possible states of the game.
 */
enum class GameState {
    READY, /**< The game is ready to start. */
    PAUSED, /**< The game is paused. */
    FINISHED /**< The game is finished. */
};

#endif // GAMESTATE_H
