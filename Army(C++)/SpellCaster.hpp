#ifndef SPELLCASTER_H
#define SPELLCASTER_H

#include "Soldier.hpp"
#include "Mana.hpp"
#include <map>

class Spell;

class SpellCaster: public Soldier {
protected:
    Mana* mana;
    enum SpellList { FIREBALL, FREEZ, FLOOD, AVALANCHE, PATCHUP, HEAL };
    std::map<SpellList, Spell&>* spellBook;
public:
    SpellCaster(const std::string& name);

    Mana& getMana() const;

    virtual void spellCast(Unit& enemy) = 0;
};

std::ostream& operator<<(std::ostream& out, const SpellCaster& spellCaster);

#endif