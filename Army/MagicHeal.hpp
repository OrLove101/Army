#ifndef MAGICHEAL_H
#define MAGICHEAL_H

#include "Spell.hpp"

class MagicHeal: public Spell {
public:
    MagicHeal(int magicPower, int manaConsume);
    ~MagicHeal();

    void spellCast(Unit& enemy, SpellCaster& thisUnit);
};

#endif