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
    Game(std::string nickname, int level);
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
    GameState getState;
    GameState getGameState() const;
    void drop();
    std::pair<Position,BrickModel> getBrickDetails();
    Board*board() const;
    int getScore();
    int getLinesCompleted();
};

#endif // GAME_H
