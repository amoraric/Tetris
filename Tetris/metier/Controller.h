#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Facade.h"
#include <memory>

/**
 * @brief The Controller class manages the flow of the game.
 */
class Controller : public Observer, public std::enable_shared_from_this<Controller> {
    std::unique_ptr<Facade> facade_; /**< The facade for controlling game interactions. */
    std::tuple<std::string, int,bool> configuration_; /**< The configuration chosen by the player. */
public:
    /**
     * @brief Starts the game.
     *        This method initiates the game loop and begins game execution.
     */
    void start();
    /**
     * @brief Updates the game state.
     *        This method is called whenever the game state changes and notifies the controller to update accordingly.
     */
    void update() override;
};

#endif // CONTROLLER_H
