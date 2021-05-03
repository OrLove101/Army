#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "Observer.hpp"

class Observable {
protected:
    Observer* observer;
public:
    Observable();

    virtual void add(Observer& observer) = 0;
    virtual void remove(Observer& observer) = 0;
    virtual void notify() = 0;
};

#endif