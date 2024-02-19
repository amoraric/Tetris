#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <memory>

class Observer;

class Observable {
public:
    virtual ~Observable() {}
    virtual void addObserver(std::shared_ptr<Observer> observer) = 0;
    virtual void removeObserver(std::shared_ptr<Observer> observer) = 0;
    virtual void notifyObservers() = 0;
};

#endif // OBSERVABLE_H
