#ifndef DIFFICULTY_H
#define DIFFICULTY_H

/**
 * @brief The Difficulty class defines the difficulty of the game
 */
class Difficulty {
    int maxScore_; /**< The maximum score achievable in the game. */
    int maxLines_; /**< The maximum number of lines that can be cleared in the game. */
    int timeLimit_; /**< The time limit for the game. */
    int level_; /**< The difficulty level of the game. */
public:
    /**
     * @brief Constructor for the Difficulty class.
     * @param level The difficulty level of the game.
     */
    Difficulty(int level);
    /**
     * @brief Gets the maximum score achievable in the game.
     * @return The maximum score.
     */
    int getMaxScore();
    /**
     * @brief Gets the maximum number of lines that can be cleared in the game.
     * @return The maximum number of lines.
     */
    int getMaxLines();
    /**
     * @brief Gets the time limit for the game.
     * @return The time limit in seconds.
     */
    int getTimeLimit();
    /**
     * @brief Sets the difficulty level of the game.
     * @param level The new difficulty level.
     */
    void setLevel(int level);
    /**
     * @brief Gets the current difficulty level of the game.
     * @return The current difficulty level.
     */
    int getLevel();
    /**
     * @brief Loads the difficulty settings from a file.
     * @return True if the settings are loaded successfully, false otherwise.
     */
    bool load();
    /**
     * @brief Moves to the next difficulty level.
     * @return True if the next difficulty level is available and set successfully, false otherwise.
     */
    bool nextDifficulty();
};

#endif // DIFFICULTY_H
