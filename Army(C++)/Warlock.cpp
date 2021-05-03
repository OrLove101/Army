#include "Warlock.hpp"

Warlock::Warlock(const std::string& name): Wizard(name) {
    this->spellBook->insert(std::pair<SpellList, Spell&>(AVALANCHE, *new MagicAttack(35, 18)));
    this->summonManaConsume = 100;
}

Deamon& Warlock::summon() const {
    if ( this->getMana().getCurrentMana() >= this->summonManaConsume ) {

        this->getMana().takeMana(this->summonManaConsume);
        return *Deamon::getDeamon();
    }
    throw OutOfMana();
}