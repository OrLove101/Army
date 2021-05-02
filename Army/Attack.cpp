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
    int potentialDamage = this->damage;

    if ( enemy.getState().isUndead() && thisUnit.getState().isPriest() ) {
        potentialDamage *= 2;
    }

    enemy.getHealth().takeDamage(potentialDamage);
    if ( thisUnit.getState().isVampire() ) {
        thisUnit.getHealth().addHitPoints(potentialDamage/2);
    }

    if ( enemy.getHealth().getHitPoints() != 0 && thisUnit.getState().isCounterAttackable() ) {
        enemy.getAttack().counterAttack(thisUnit, enemy);
    }
}

void Attack::counterAttack(Unit& enemy, Unit& you) {
    int potentialDamage = this->damage;

    if ( you.getState().isUndead() && enemy.getState().isPriest() ) {
        potentialDamage *= 2;
    }

    enemy.getHealth().takeDamage(potentialDamage/2);

    if ( you.getState().isVampire() ) {
        you.getHealth().addHitPoints(potentialDamage/4);
    }
}