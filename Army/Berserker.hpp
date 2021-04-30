#ifndef BERSERKER_H
#define BERSERKER_H

#include "Unit.hpp"

class Berserker: public Unit {
public:
    Berserker(const std::string& name);
    ~Berserker();

    void takeDamage(int dmg);
    void attack(Unit& enemy);
    void counterAttack(Unit& enemy);
};

#endif