#ifndef PLAYER_H
#define PLAYER_H

#include <string>

/**
 * @brief The User class represents a player in the game.
 */
class Player {
    std::string nickname_; /**< The nickname of the player. */
    int score_; /**< The score of the player. */
    int linesCompleted_; /**< The number of lines completed by the player. */
public:
    /**
     * @brief Constructor for the User class.
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
    void increaseLinesCount(int count);
    int getScore();
    int getLinesCompleted();
};

inline int Player::getLinesCompleted()
{

}

#endif // PLAYER_H
