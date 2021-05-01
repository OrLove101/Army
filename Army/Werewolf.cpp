#include "Werewolf.hpp"
#include "Attack.hpp"

    Werewolf::Werewolf(const std::string& name): Unit(name) {
        this->getState().makeWerewolf();
    }
    Werewolf::~Werewolf() {}

    void Werewolf::takeDamage(int dmg) {
        this->getHealth().takeDamage(dmg);
    }
    void Werewolf::attack(Unit& enemy) {
        this->getAttack().attack(enemy, *this);
    }
    void Werewolf::counterAttack(Unit& enemy) {
        this->getAttack().counterAttack(enemy, *this);
    }
    void Werewolf::transform(Unit& enemy) {
        this->getAbility().transform(enemy, *this);
    }
    void Werewolf::transform() {
        this->getAbility().transform(*this);
    }