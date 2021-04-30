#ifndef ATTACK_H
#define ATTACK_H

#include <iostream>
#include "Health.hpp"

class Unit;

class Attack {
protected:
    int damage;
    Health health;
    // Unit& thisUnit;
public:
    Attack(Health& health/*, Unit& thisUnit*/);
    ~Attack();

    void attack(Unit& enemy);
    void counterAttack(Unit& enemy);

    int getDamage() const;
    void setDamage(int damage);
};

#endif