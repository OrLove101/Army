#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Unit.hpp"

class Vampire: public Unit {
public:
    Vampire(const std::string& name);
    ~Vampire();

    void takeDamage(int dmg);
    void attack(Unit& enemy);
    void counterAttack(Unit& enemy);
};

#endif