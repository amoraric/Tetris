#ifndef PLAYER_H
#define PLAYER_H

#include <string>

/**
 * @brief The Player class represents a player in the game.
 */
class Player {
    std::string nickname_; /**< The nickname of the player. */
    int score_; /**< The score of the player. */
    int linesCompleted_; /**< The number of lines completed by the player. */
public:
    /**
     * @brief Constructor for the Player class.
     */
    Player(std::string nickname);
    /**
     * @brief Increases the score of the player based on the number of lines cleared.
     * @param linesCleared The number of lines cleared.
     */
    void increaseScore(int linesCleared, int level, int distance);
    /**
     * @brief Increases the count of lines completed by the player.
     * @param count The number of lines completed.
     */
    /**
     * @brief Increases the count of lines completed by the player.
     * @param count The number of lines completed.
     */
    void increaseLinesCount(int count);
    /**
     * @brief Gets the current score of the player.
     * @return The current score of the player.
     */
    int getScore();
    /**
     * @brief Gets the number of lines completed by the player.
     * @return The number of lines completed by the player.
     */
    int getLinesCompleted();
    /**
     * @brief Gets the nickname of the player.
     * @return The nickname of the player.
     */
    std::string getNickname();
};

#endif // PLAYER_H
