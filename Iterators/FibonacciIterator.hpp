#ifndef FIBONACCIITERATOR_H
#define FIBONACCIITERATOR_H

class FibonacciIterator {
private:
    int limit;
    int current;
    int first;

int fibonacci(int current);
public:
    FibonacciIterator(int limit, int current);
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