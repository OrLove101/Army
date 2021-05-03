#ifndef MAGIC_H
#define MAGIC_H

#include "Spell.hpp"

class MagicAttack: public Spell {
public:
    MagicAttack(int magicPower, int manaConsume);
    ~MagicAttack();

    void spellCast(Unit& enemy, SpellCaster& thisUnit);
};

#endif