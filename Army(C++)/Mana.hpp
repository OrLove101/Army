#ifndef MANA_H
#define MANA_H

#include <iostream>

class Mana {
private:
    int manaLimit;
    int currentMana;
public:
    Mana();
    ~Mana();

    bool ensureHaveMana();
    void takeMana(int mana);

    int getManaLimit() const;
    int setManaLimit(int manaLimit);

    int getCurrentMana() const;
    int setCurrentMana(int currentMana);
};

#endif