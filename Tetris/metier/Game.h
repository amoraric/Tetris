#ifndef GAME_H
#define GAME_H

#include <memory>

#include "GameState.h"
#include "Board.h"
#include "Brick.h"
#include "Direction.h"
#include "Difficulty.h"
#include "BrickBag.h"
#include "Player.h"


/**
 * @brief The Game class represents the game state and logic.
 */
class Game {
    std::unique_ptr<Board> board_; /**< The game board. */
    std::unique_ptr<BrickBag> bag_; /**< The bag of shapes. */
    std::unique_ptr<Player> player_; /**< The player. */
    std::unique_ptr<Brick> currentBrick_; /**< The current brick. */
    std::unique_ptr<Difficulty> difficulty_; /**< The game difficulty. */
    GameState gameState_; /**< The game state. */
    int currentTime_; /**< The current time in the game. */
public:
    /**
     * @brief Constructor for the Game class.
     */
    Game(std::string nickname, int level, int rows, int columns);
    /**
     * @brief Generates a new shape on the board.
     */
    void generate();
    /**
     * @brief Calculates the score based on the game state.
     */
    void calculateScore();
    /**
     * @brief Updates the game state based on the direction of movement.
     * @param direction The direction of movement.
     */
    bool update(Direction direction);
    /**
     * @brief Updates the game state based on the rotation direction.
     * @param clockwise If true, rotates the current brick clockwise; otherwise, counterclockwise.
     */
    void update(bool clockwise);
    /**
     * @brief Updates the game state to the specified state.
     * @param state The new game state.
     */
    void updateState(GameState state);
    /**
     * @brief Checks if the game is over.
     * @return True if the game is over, false otherwise.
     */
    bool isGameOver() const;
    /**
     * @brief Returns the current state of the game
     * @return Instance of type GameState
     */
    GameState getGameState() const;
    /**
     * @brief Drops the current brick to the lowest possible position on the board.
     */
    void drop();
    /**
     * @brief Returns the details of the current brick, including its position and model.
     * @return A pair containing the position and model of the current brick.
     */
    std::pair<Position,BrickModel> getBrickDetails();
    /**
     * @brief Returns a pointer to the game board.
     * @return A pointer to the game board.
     */
    Board* board() const;
    /**
     * @brief Returns the current score of the player.
     * @return The current score of the player.
     */
    int getScore();
    /**
     * @brief Returns the number of lines completed by the player.
     * @return The number of lines completed by the player.
     */
    int getLinesCompleted();
    /**
     * @brief currentBrick Returns the current brick
     * @return the current brick
     */
    Brick*currentBrick() const;
};

#endif // GAME_H
