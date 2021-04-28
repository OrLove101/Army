#include "Soldier.hpp"
#include "Attack.hpp"

Soldier::Soldier(const std::string& name): Unit(name) {}

Soldier::~Soldier() {}

void Soldier::takeDamage(int dmg) {
    this->getHealth().takeDamage(dmg);
}

void Soldier::attack(Unit& enemy) {
    this->getAttack().attack(enemy);
}

void Soldier::counterAttack(Unit& enemy) {
    this->getAttack().counterAttack(enemy);
} 
