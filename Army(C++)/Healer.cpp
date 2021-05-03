#include "Healer.hpp"

Healer::Healer(const std::string& name): Wizard(name) {
    this->getState().makeHealer();
    this->spellBook->insert(std::pair<SpellList, Spell&>(HEAL, *new MagicHeal(100, 35)));
}