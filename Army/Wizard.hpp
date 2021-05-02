#ifndef WIZARD_H
#define WIZARD_H

#include "SpellCaster.hpp"
#include "MagicAttack.hpp"
#include "MagicHeal.hpp"

class Wizard: public SpellCaster {
    public:
        Wizard(const std::string& name);

        void spellCast(Unit& enemy);
};

#endif