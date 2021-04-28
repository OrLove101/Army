#include "Health.hpp"

void Health::addHitPoints(int hp) {
    if ( ensureIsAlive() ) {
        int potentialHp;

        potentialHp = this->hitPoints + hp;
        if ( potentialHp > this->hitPointsLimit ) {
            potentialHp = this->hitPointsLimit;
        }
        this->hitPoints = potentialHp;
    }
}

Health::Health() {
    this->hitPointsLimit = 100;
    this->hitPoints = this->hitPointsLimit;
}
Health::~Health() {}

void Health::takeDamage(int dmg) {
    if ( ensureIsAlive() ) {
        int potentialHp;

        potentialHp = this->hitPoints - dmg;
        if ( potentialHp < 0 ) {
            potentialHp = 0;
        }
        this->hitPoints = potentialHp;
    }
}

bool Health::ensureIsAlive() {
    return this->hitPoints > 0;
}
int Health::getHitPoints() const {
    return this->hitPoints;
}
int Health::getHitPointsLimit() const {
    return this->hitPointsLimit;
}
void Health::setHitPoints(int hitPoints) {
    this->hitPoints = hitPoints;
}
void Health::setHitPointsLimit(int hitPointsLimit) {
    this->hitPointsLimit = hitPointsLimit;
}