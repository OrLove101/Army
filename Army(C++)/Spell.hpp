#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "Health.hpp"
#include "State.hpp"

class Unit;
class SpellCaster;

class Spell {
protected:
    int magicPower;
    int manaConsume;
public:
    Spell(int magicPower, int manaConsume);
    ~Spell();

    virtual void spellCast(Unit& enemy, SpellCaster& thisUnit) = 0;
};

#endif