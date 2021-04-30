#include "Soldier.hpp"
#include "Attack.hpp"

Soldier::Soldier(const std::string& name): Unit(name) {}

Soldier::~Soldier() {}

void Soldier::takeDamage(int dmg) {
    this->getHealth().takeDamage(dmg);
}

void Soldier::attack(Unit& enemy) {
    this->getAttack().attack(enemy, *this);
}

void Soldier::counterAttack(Unit& enemy) {
    this->getAttack().counterAttack(enemy, *this);
}

void Soldier::transform(Unit& enemy) {
    this->getAbility().transform(enemy, *this);
}
