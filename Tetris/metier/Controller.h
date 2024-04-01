#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Facade.h"
class Controller : Observer{
    std::unique_ptr<Facade> facade_;
public:
    Controller();
    void start();
    void update() override;
    ~Controller() override;

};


#endif // CONTROLLER_H
