#ifndef ARRAYITER_H
#define ARRAYITER_H

#include <iostream>

class InvalideStatement {};

template <typename Type>
class ArrayIterator {
private:
    int limit;
    int current;
    int first;
    Type* arrayPointer;

public:
    ArrayIterator(int limit, Type array[], int current);
    ~ArrayIterator();
    void next();
    void previous();

    void operator++();
    void operator++(int);

    void operator--();
    void operator--(int);

    bool over();

    bool start();

    Type value();
    Type operator*();
};

#endif