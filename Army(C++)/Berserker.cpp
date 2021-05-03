#include "Berserker.hpp"

Berserker::Berserker(const std::string& name): Soldier(name) {
    this->getState().setMagicResist();
}