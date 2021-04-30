#include "Rogue.hpp"
#include "Attack.hpp"

    Rogue::Rogue(const std::string& name): Unit(name) {
        this->getState().setCounterAttackResist();
    }
    Rogue::~Rogue(){}

    void Rogue::takeDamage(int dmg){
        this->getHealth().takeDamage(dmg);
    }
    void Rogue::attack(Unit& enemy){
        this->getAttack().attack(enemy, *this);
    }
    void Rogue::counterAttack(Unit& enemy){
        this->getAttack().counterAttack(enemy);
    }