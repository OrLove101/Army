#include "MagicAttack.hpp"
#include "SpellCaster.hpp"
#include "Unit.hpp"

MagicAttack::MagicAttack(int magicPower, int manaConsume): Spell(magicPower, manaConsume) {}
MagicAttack::~MagicAttack() {}

void MagicAttack::spellCast(Unit& enemy, SpellCaster& thisUnit) {

    if ( thisUnit.getMana().getCurrentMana() >= this->manaConsume ) {
        int potentialPower = this->magicPower;

        if ( thisUnit.getState().isHealer() ) {
            potentialPower /= 2;
        }
        if ( enemy.getState().isCanTakeMagicDamage() ) {
            enemy.getHealth().takeDamage(potentialPower);
        }
        thisUnit.getMana().takeMana(this->manaConsume);
    }
}