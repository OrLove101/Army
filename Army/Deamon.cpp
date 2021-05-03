#include "Deamon.hpp"
#include "Attack.hpp"

Deamon::Deamon(const std::string& name): Soldier(name) {
    this->getHealth().setHitPointsLimit(1000);
    this->getHealth().setHitPoints(1000);
    this->getAttack().setDamage(250);
}

Deamon* Deamon::getDeamon() {
    if ( !Deamon::singletoneDeamon ) {
        Deamon::singletoneDeamon = new Deamon();
    }
    return Deamon::singletoneDeamon;
}

Deamon* Deamon::singletoneDeamon = NULL;