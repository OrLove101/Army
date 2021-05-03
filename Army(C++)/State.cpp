#include "State.hpp"

State::State() {
    this->counterAttackable = true;
    this->canTakeMagicDamage = true;
    this->unitIsVampire = false;
    this->unitIsWerewolf = false;
    this->unitIsWolf = false;
    this->unitIsHealer = false;
    this->unitIsPriest = false;
    this->unitIsUndead = false;
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

bool State::isVampire() const {
    return this->unitIsVampire;
}

void State::makeVampire() {
    this->unitIsVampire = true;
}

bool State::isWerewolf() const {
    return this->unitIsWerewolf;
}

void State::makeWerewolf() {
    this->unitIsWerewolf = true;
}

bool State::isWolf() const {
    return this->unitIsWolf;
}

void State::wereWolfTransform() {
    this->unitIsWolf = !this->unitIsWolf;
}

bool State::isHealer() const {
    return this->unitIsHealer;
}

void State::makeHealer() {
    this->unitIsHealer = true;
}


bool State::isUndead() const {
    return this->unitIsUndead;
}

void State::makeUndead() {
    this->unitIsUndead = true;
}

bool State::isPriest() const {
    return this->unitIsPriest;
}

void State::makePriest() {
    this->unitIsPriest = true;
}