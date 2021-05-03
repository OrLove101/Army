#ifndef HEALER_H
#define HEALER_H

#include "Wizard.hpp"

class Healer: public Wizard {
public:
    Healer(const std::string& name);
};

#endif