#ifndef PRIEST_H
#define PRIEST_H

#include "Healer.hpp"

class Priest: public Healer {
public:
    Priest(const std::string& name);
};

#endif