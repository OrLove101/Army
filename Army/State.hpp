#ifndef STATE_H
#define STATE_H

#include <iostream>

class State {
private:
    bool counterAttackable;
    bool canTakeMagicDamage;
    bool unitIsVampire;
public:
    State();
    ~State();

    bool isCounterAttackable() const;
    void setCounterAttackResist();

    bool isCanTakeMagicDamage() const;
    void setMagicResist();

    bool isVampire() const;
    void makeVampire();
};
#endif