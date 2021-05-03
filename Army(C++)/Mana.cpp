#include "Mana.hpp"

Mana::Mana() {
    this->manaLimit = 100;
    this->currentMana = this->manaLimit;
}
Mana::~Mana() {}

bool Mana::ensureHaveMana() {
    return this->currentMana > 0;
}
void Mana::takeMana(int mana) {
    int potentialMana;

    potentialMana = this->currentMana - mana;
    this->currentMana = potentialMana;
}

int Mana::getManaLimit() const {
    return this->manaLimit;
}
int Mana::setManaLimit(int manaLimit) {
    this->manaLimit = manaLimit;
}

int Mana::getCurrentMana() const {
    return this->currentMana;
}
int Mana::setCurrentMana(int currentMana) {
    this->currentMana = currentMana;
}