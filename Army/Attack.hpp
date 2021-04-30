#ifndef ATTACK_H
#define ATTACK_H

#include <iostream>
#include "Health.hpp"
#include "State.hpp"

class Unit;

class Attack {
protected:
    int damage;
    State state;
    Health health;
public:
    Attack(/*Health& health, State& state*/);
    ~Attack();

    void attack(Unit& enemy, Unit& thisUnit);
    void counterAttack(Unit& enemy);

    int getDamage() const;
    void setDamage(int damage);
};

#endif