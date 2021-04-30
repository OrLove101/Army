#include "Ability.hpp"
#include "Unit.hpp"

    Ability::Ability() {}
    Ability::~Ability() {}
    
    void Ability::transform(Unit& enemy, Unit& you) {
        if ( you.getState().isVampire() ) {
            enemy.getState().makeVampire();
        }
    }