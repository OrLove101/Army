#include "Ability.hpp"
#include "Unit.hpp"
#include "Attack.hpp"

Ability::Ability() {}
Ability::~Ability() {}

void Ability::transform(Unit& enemy, Unit& you) {
    if ( you.getState().isVampire() && !enemy.getState().isWerewolf() ) {
        enemy.getState().makeVampire();
    }
    if ( you.getState().isWerewolf() && !enemy.getState().isVampire() ) {
        enemy.getState().makeWerewolf();
    }
}

void Ability::transform(Unit& you) {
    if ( you.getState().isWerewolf() && !you.getState().isWolf() ) {
        int wolfHp = 200;
        int wolfDamage = 40;

        you.getState().wereWolfTransform();

        you.getHealth().setHitPointsLimit(wolfHp);
        you.getHealth().setHitPoints(wolfHp);

        you.getAttack().setDamage(wolfDamage);
    } else if ( you.getState().isWerewolf() ) {
        int humanHp = 100;
        int humanDamage = 10;

        you.getState().wereWolfTransform();

        you.getHealth().setHitPointsLimit(humanHp);
        you.getHealth().setHitPoints(humanHp);

        you.getAttack().setDamage(humanDamage);
    }
}