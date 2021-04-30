#ifndef STATE_H
#define STATE_H

#include <iostream>

class State {
private:
    bool counterAttackable;
    bool canTakeMagicDamage;
public:
    State();
    ~State();

    bool isCounterAttackable() const;
    void setCounterAttackResist();

    bool isCanTakeMagicDamage() const;
    void setMagicResist();
};
#endif