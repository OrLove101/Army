#ifndef DEAMON_H
#define DEAMON_H

#include "Soldier.hpp"

class Deamon: public Soldier {
private:
    static Deamon* singletoneDeamon;
    Deamon(const std::string& name="Deamon");
public:
    static Deamon* getDeamon();
};

#endif