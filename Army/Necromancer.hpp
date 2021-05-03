#ifndef NECROMANCER_H
#define NECROMANCER_H

#include "Wizard.hpp"
#include "Observer.hpp"

class Necromancer: public Wizard, public Observer {
public:
    Necromancer(const std::string& name);

    void update();
    void spellCast(Unit& enemy);
    void attack(Unit& enemy);
    void counterAttack(Unit& enemy);
};

#endif