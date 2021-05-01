#include "SpellCaster.hpp"
#include "Attack.hpp"

SpellCaster::SpellCaster(const std::string& name): Soldier(name) {
    this->getHealth().setHitPointsLimit(50);
    this->getHealth().setHitPoints(50);
    this->getAttack().setDamage(3);
}

Mana& SpellCaster::getMana() const {
    return *this->mana;
}

std::ostream& operator<<(std::ostream& out, const SpellCaster& spellCaster) {
    out << spellCaster.getName() << " " << spellCaster.getHealth().getHitPoints() << "/" << spellCaster.getHealth().getHitPointsLimit() << "hp, damage: " << spellCaster.getAttack().getDamage();
    out << " mana: " << spellCaster.getMana().getCurrentMana() << "/" << spellCaster.getMana().getManaLimit();

    return out;
}