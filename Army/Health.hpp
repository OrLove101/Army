#ifndef HEALTH_H
#define HEALTH_H

#include <iostream>

class Health {
protected:
    int hitPointsLimit;
    int hitPoints;
    void addHitPoints(int hp);
public:
    Health();
    ~Health();

    bool ensureIsAlive();
    void takeDamage(int dmg);

    int getHitPoints() const;
    int getHitPointsLimit() const;
    void setHitPoints(int hitPoints);
    void setHitPointsLimit(int hitPointsLimit);
};

#endif