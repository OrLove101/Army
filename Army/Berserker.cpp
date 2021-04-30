#include "Berserker.hpp"
#include "Attack.hpp"

    Berserker::Berserker(const std::string& name): Unit(name) {
        this->getState().setMagicResist();
    }
    Berserker::~Berserker() {}

    void Berserker::takeDamage(int dmg) {
        this->getHealth().takeDamage(dmg);
    }
    void Berserker::attack(Unit& enemy) {
        this->getAttack().attack(enemy, *this);
    }
    void Berserker::counterAttack(Unit& enemy) {
        this->getAttack().counterAttack(enemy, *this);
    }
    void Berserker::transform(Unit& enemy) {
        this->getAbility().transform(enemy, *this);
    }