#include "State.hpp"

State::State() {
    this->counterAttackable = true;
    this->canTakeMagicDamage = true;
}
State::~State() {}

bool State::isCounterAttackable() const {
    return this->counterAttackable;
}

void State::setCounterAttackResist() {
    this->counterAttackable = false;
}

bool State::isCanTakeMagicDamage() const {
    return this->canTakeMagicDamage;
}

void State::setMagicResist() {
    this->canTakeMagicDamage = false;
}