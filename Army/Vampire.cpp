#include "Vampire.hpp"

Vampire::Vampire(const std::string& name): Soldier(name) {
    this->getState().makeVampire();
}