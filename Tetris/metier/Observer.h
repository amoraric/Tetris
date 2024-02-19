#ifndef OBSERVER_H
#define OBSERVER_H

/**
 * @brief The Observer class represents an object that observes changes in an Observable object.
 */
class Observer {
public:
    /**
     * @brief Destructor for the Observer class.
     */
    virtual ~Observer() {}
    /**
     * @brief Update method called by the Observable object when a change occurs.
     */
    virtual void update() = 0;
};

#endif // OBSERVER_H
