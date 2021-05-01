#ifndef STATE_H
#define STATE_H

#include <iostream>

class State {
private:
    bool counterAttackable;
    bool canTakeMagicDamage;
    bool unitIsVampire;
    bool unitIsWerewolf;
    bool unitIsWolf;
public:
    State();
    ~State();

    bool isCounterAttackable() const;
    void setCounterAttackResist();

    bool isCanTakeMagicDamage() const;
    void setMagicResist();

    bool isVampire() const;
    void makeVampire();

    bool isWerewolf() const;
    void makeWerewolf();

    bool isWolf() const;
    void wereWolfTransform();
};
#endif