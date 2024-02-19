#ifndef FACADE_H
#define FACADE_H

#include <memory>
#include <vector>

#include "Observable.h"
#include "Game.h"
#include "Direction.h"

class Game;
class Direction;
class Observable;

/**
 * @brief The Facade class provides a simplified interface to interact with the game.
 */
class Facade : public Observable {
    std::unique_ptr<Game> game_; /**< The game instance. */
    std::vector<std::shared_ptr<Observer>> observers_; /**< List of observers. */
public:
    /**
     * @brief Constructor for the Facade class.
     */
    Facade();
    /**
     * @brief Destructor for the Facade class.
     */
    ~Facade();
    /**
     * @brief Starts the game.
     */
    void start();
    /**
     * @brief Pauses the game.
     */
    void pause();
    /**
     * @brief Resumes the game.
     */
    void resume();
    /**
     * @brief Ends the game.
     */
    void end();
    /**
     * @brief Moves the current brick in the specified direction.
     * @param direction The direction to move the brick.
     */
    void translation(Direction direction);
    /**
     * @brief Rotates the current brick clockwise or counterclockwise.
     * @param clockwise If true, rotates the brick clockwise; otherwise, counterclockwise.
     */
    void rotation(bool clockwise);
    /**
     * @brief Drops the current brick to the lowest possible position.
     */
    void drop();
    /**
     * @brief Adds an observer to the list of observers.
     * @param observer The observer to add.
     */
    void addObserver(std::shared_ptr<Observer> observer) override;
    /**
     * @brief Removes an observer from the list of observers.
     * @param observer The observer to remove.
     */
    void removeObserver(std::shared_ptr<Observer> observer) override;
    /**
     * @brief Notifies all observers.
     */
    void notifyObservers() override;
};

#endif // FACADE_H
