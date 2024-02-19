#ifndef FACADE_H
#define FACADE_H

#include <memory>
#include <vector>

#include "Observable.h"

class Game;
class Direction;

class Facade : public Observable {
    std::unique_ptr<Game> game_;
    std::vector<std::shared_ptr<Observer>> observers_;
public:
    Facade();
    ~Facade();
    void start();
    void pause();
    void resume();
    void end();
    void translation(Direction direction);
    void rotation(bool clockwise);
    void drop();
    void addObserver(std::shared_ptr<Observer> observer) override;
    void removeObserver(std::shared_ptr<Observer> observer) override;
    void notifyObservers() override;
};

#endif // FACADE_H
