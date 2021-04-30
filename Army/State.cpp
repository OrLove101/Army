#include "State.hpp"

State::State() {
    this->counterAttackable = true;
}
State::~State() {}

bool State::isCounterAttackable() const {
    return this->counterAttackable;
}

void State::setCounterAttackResist() {
    this->counterAttackable = false;
}