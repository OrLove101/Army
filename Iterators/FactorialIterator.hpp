#ifndef FACTORIALITERATOR_H
#define FACTORIALITERATOR_H

class InvalideStatement {};

class FactorialIterator {
private:
    int limit;
    int current;
    int first;

    int factorial(int n);
public:
    FactorialIterator(int limit, int current);

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