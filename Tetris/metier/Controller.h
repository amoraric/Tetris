#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Facade.h"
#include <memory>

class Controller : public Observer, public std::enable_shared_from_this<Controller> {
    std::unique_ptr<Facade> facade_;
public:
    // Controller();
    void start();
    void update() override;
    // ~Controller() override;
};

#endif // CONTROLLER_H
