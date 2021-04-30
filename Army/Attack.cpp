#include "Attack.hpp"
#include "Unit.hpp"

Attack::Attack() {
    this->damage = 10;
}

Attack::~Attack() {}

void Attack::setDamage(int damage) {
    this->damage = damage;
}

int Attack::getDamage() const {
    return this->damage;
}

void Attack::attack(Unit& enemy, Unit& thisUnit) {
    enemy.getHealth().takeDamage(this->damage);

    if ( thisUnit.getState().isVampire() ) {
        thisUnit.getHealth().addHitPoints(this->damage/2);
    }

    if ( enemy.getHealth().getHitPoints() != 0 && thisUnit.getState().isCounterAttackable() ) {
        enemy.getAttack().counterAttack(thisUnit, enemy);
    }
}

void Attack::counterAttack(Unit& enemy, Unit& you) {
    enemy.getHealth().takeDamage(this->damage/2);

    if ( you.getState().isVampire() ) {
        you.getHealth().addHitPoints(this->damage/4);
    }
}