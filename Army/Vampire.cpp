#include "Vampire.hpp"
#include "Attack.hpp"

    Vampire::Vampire(const std::string& name): Unit(name) {
        this->getState().makeVampire();
    }
    Vampire::~Vampire() {}

    void Vampire::takeDamage(int dmg) {
        this->getHealth().takeDamage(dmg);
    }
    void Vampire::attack(Unit& enemy) {
        this->getAttack().attack(enemy, *this);
    }
    void Vampire::counterAttack(Unit& enemy) {
        this->getAttack().counterAttack(enemy, *this);
    }

    void Vampire::transform(Unit& enemy) {
        this->getAbility().transform(enemy, *this);
    }