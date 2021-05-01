#ifndef WAREWOLF_H
#define WAREWOLF_H

#include "Unit.hpp"

class Werewolf: public Unit {
public:
    Werewolf(const std::string& name);
    ~Werewolf();

    void takeDamage(int dmg);
    void attack(Unit& enemy);
    void counterAttack(Unit& enemy);
    void transform(Unit& enemy);
    void transform();
};

#endif