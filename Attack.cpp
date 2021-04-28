#include "Attack.hpp"
#include "Unit.hpp"

Attack::Attack( Health& health ) {
    this->health = health;
}

Attack::~Attack() {}

void Attack::setDamage(int damage) {
    this->damage = damage;
}

int Attack::getDamage() const {
    return this->damage;
}

void Attack::attack(Unit& enemy) {
    enemy.getHealth().takeDamage(this->damage);

    if ( enemy.getHealth().getHitPoints() != 0 ) {
        enemy.getAttack().counterAttack(enemy);
    }
}

void Attack::counterAttack(Unit& enemy) {
    enemy.getHealth().takeDamage(this->damage/2);
}