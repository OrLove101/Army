#ifndef STATE_H
#define STATE_H

#include <iostream>

class State {
private:
    bool counterAttackable;
public:
    State();
    ~State();

    bool isCounterAttackable() const;

    void setCounterAttackResist();
};
#endif