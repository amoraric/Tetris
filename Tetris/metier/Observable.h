#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <memory>

class Observer;

/**
 * @brief The Observable class represents an object that can be observed by observers.
 */
class Observable {
public:
    /**
     * @brief Destructor for the Observable class.
     */
    virtual ~Observable() {}
    /**
     * @brief Adds an observer to the list of observers.
     * @param observer The observer to add.
     */
    virtual void addObserver(std::shared_ptr<Observer> observer) = 0;
    /**
     * @brief Removes an observer from the list of observers.
     * @param observer The observer to remove.
     */
    virtual void removeObserver(std::shared_ptr<Observer> observer) = 0;
    /**
     * @brief Notifies all observers.
     */
    virtual void notifyObservers() = 0;
};

#endif // OBSERVABLE_H
