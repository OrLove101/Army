#ifndef ARITHMETICITERATOR_H
#define ARITHMETICITERATOR_H

class ArithmeticIterator {
private:
    int limit;
    int current;
    int step;
    int first;

public:
    ArithmeticIterator(int limit, int step, int current);

    ~ArithmeticIterator();

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