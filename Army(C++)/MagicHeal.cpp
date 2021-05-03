#include "MagicHeal.hpp"
#include "SpellCaster.hpp"
#include "Unit.hpp"

MagicHeal::MagicHeal(int magicPower, int manaConsume): Spell(magicPower, manaConsume) {}
MagicHeal::~MagicHeal() {}

void MagicHeal::spellCast(Unit& enemy, SpellCaster& thisUnit) {
    
    if ( thisUnit.getMana().getCurrentMana() >= this->manaConsume ) {
        int potentialPower = this->magicPower;

        if ( !thisUnit.getState().isHealer() ) {
            potentialPower /= 2;
        }
        if ( enemy.getState().isCanTakeMagicDamage() ) {
            enemy.getHealth().addHitPoints(potentialPower);
        }
        thisUnit.getMana().takeMana(this->manaConsume);
    }
}