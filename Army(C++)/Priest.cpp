#include "Priest.hpp"

Priest::Priest(const std::string& name): Healer(name) {
    this->getState().makePriest();
}