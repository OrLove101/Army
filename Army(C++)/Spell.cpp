#include "Spell.hpp"
#include "Unit.hpp"

Spell::Spell(int magicPower, int manaConsume) {
    this->magicPower = magicPower;
    this->manaConsume = manaConsume;
}
Spell::~Spell() {}