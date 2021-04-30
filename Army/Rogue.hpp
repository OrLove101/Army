#ifndef ROGUE_H
#define ROGUE_H

#include "Unit.hpp"

class Rogue: public Unit {
public:
    Rogue(const std::string& name);
    ~Rogue();

    void takeDamage(int dmg);
    void attack(Unit& enemy);
    void counterAttack(Unit& enemy);
};

#endif