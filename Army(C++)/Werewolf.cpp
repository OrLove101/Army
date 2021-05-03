#include "Werewolf.hpp"

Werewolf::Werewolf(const std::string& name): Soldier(name) {
    this->getState().makeWerewolf();
}