#ifndef ATTACK_H
#define ATTACK_H

#include <iostream>
#include "Health.hpp"

class Unit;

class Attack {
protected:
    int damage;
    Health health;
public:
    Attack(Health& health);
    ~Attack();

    void attack(Unit& enemy);
    void counterAttack(Unit& enemy);

    int getDamage() const;
    void setDamage(int damage);
};

#endif