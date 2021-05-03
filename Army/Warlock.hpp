#ifndef WARLOCK_H
#define WARLOCK_H

#include "Wizard.hpp"
#include "Deamon.hpp"

class OutOfMana {};

class Warlock: public Wizard {
private:
    int summonManaConsume;
public:
    Warlock(const std::string& name);

    Deamon& summon() const;
};

#endif