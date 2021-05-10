#ifndef PRIMEITERATOR_H
#define PRIMEITERATOR_H

class InvalideStatement {};

class PrimeIterator {
private:
    int limit;
    int current;
    int first;

int prime(int current);

public:
    PrimeIterator(int limit, int current);

    void next();
    void previous();
    void operator++();

    void operator++(int);

    void operator--();

    void operator--(int);

    bool over();

    bool start();

    int value();

    int operator*();
};

#endif