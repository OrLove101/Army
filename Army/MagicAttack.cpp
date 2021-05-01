#include "MagicAttack.hpp"
#include "SpellCaster.hpp"
#include "Unit.hpp"

MagicAttack::MagicAttack(int magicPower, int manaConsume): Spell(magicPower, manaConsume) {}
MagicAttack::~MagicAttack() {}

void MagicAttack::spellCast(Unit& enemy, SpellCaster& thisUnit) {
    if ( enemy.getState().isCanTakeMagicDamage() ) {
        if ( thisUnit.getMana().getCurrentMana() >= this->manaConsume ) {
            enemy.getHealth().takeDamage(this->magicPower);

            thisUnit.getMana().takeMana(this->manaConsume);
        }
    }
}