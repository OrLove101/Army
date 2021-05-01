#include "Rogue.hpp"

Rogue::Rogue(const std::string& name): Soldier(name) {
    this->getState().setCounterAttackResist();
}