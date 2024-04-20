#ifndef VIEW_H
#define VIEW_H
#include "Board.h"
#include <string>
#include <tuple>

/**
 * @brief The View class handles user interface interactions.
 */
class View {
public:
    /**
     * @brief Displays a welcome message.
     */
    static void welcome();
    /**
     * @brief Displays the game board along with the current brick position and model.
     * @param board The game board.
     * @param p The position of the current brick.
     * @param b The model of the current brick.
     */
    static void display(Board board, Position p, BrickModel b);
    /**
     * @brief Configures game settings.
     * @return A tuple containing the player's nickname, selected difficulty level, and whether to load a saved game.
     */
    static std::tuple<std::string, int, bool, int, int> configure();
    /**
     * @brief Displays a game over message.
     */
    static void gameOver();
    /**
     * @brief Asks the user for their next action.
     * @return The user's selected action as a string.
     */
    static std::string askAction();
    /**
     * @brief Displays the player's statistics.
     * @param nickname The player's nickname.
     * @param level The difficulty level of the game.
     * @param score The player's current score.
     * @param linesCompleted The number of lines completed by the player.
     */
    static void showStats(std::string nickname, int level, int score, int linesCompleted);
};

#endif // VIEW_H
