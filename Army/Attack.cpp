#include "Attack.hpp"
#include "Unit.hpp"

Attack::Attack(Health& health/*, Unit& thisUnit*/) {
    this->health = health;
    this->damage = 10;
    // this->thisUnit = thisUnit;
}

Attack::~Attack() {}

void Attack::setDamage(int damage) {
    this->damage = damage;
}

int Attack::getDamage() const {
    return this->damage;
}

void Attack::attack(Unit& enemy) {//передавать в эту атаку как параметр указатель на унит
    //в наследнике унит при переопределении атаки вставлять this
    enemy.getHealth().takeDamage(this->damage);

    if ( enemy.getHealth().getHitPoints() != 0 ) {
        enemy.getAttack().counterAttack(enemy);
    }
}

void Attack::counterAttack(Unit& enemy) {
    enemy.getHealth().takeDamage(this->damage/2);
}