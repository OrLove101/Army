#include "Unit.hpp"
#include "Attack.hpp"

Unit::Unit(const std::string& name) {
    this->name = name;

    this->state = new State();
    this->health = new Health();
    this->unitAttack = new Attack(/**this->health, *this->state*/);
}

Unit::~Unit() {}


Health& Unit::getHealth() const {
    return *this->health;
}
Attack& Unit::getAttack() const {
    return *this->unitAttack;
}
State& Unit::getState() const {
    return *this->state;
}

const std::string& Unit::getName() const {
    return this->name;
}


std::ostream& operator<<(std::ostream& out, const Unit& unit) {
    out << unit.getName() << " " << unit.getHealth().getHitPoints() << "/" << unit.getHealth().getHitPointsLimit() << "hp, damage: " << unit.getAttack().getDamage();

    return out;
}