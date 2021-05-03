#ifndef ABILITY_H
#define ABILITY_H

#include <iostream>

class Unit;

class Ability {
public:
    Ability();
    ~Ability();

     void transform(Unit& enemy, Unit& you);
     void transform(Unit& you);
};

#endif