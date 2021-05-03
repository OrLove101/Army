#include "Necromancer.hpp"

Necromancer::Necromancer(const std::string& name): Wizard(name) {}

void Necromancer::update() {
    int heal = 25;

    this->getHealth().addHitPoints(heal);
}

void Necromancer::spellCast(Unit& enemy) {
    Wizard::spellCast(enemy);
    enemy.add(*this);
}

void Necromancer::attack(Unit& enemy) {
    Wizard::attack(enemy);
    enemy.add(*this);
}
void Necromancer::counterAttack(Unit& enemy) {
    Wizard::counterAttack(enemy);
    enemy.add(*this);
}