#ifndef GEOMETRICITERATOR_H
#define GEOMETRICITERATOR_H

class GeometricIterator {
private:
    int limit;
    int current;
    int step;
    int first;

public:
    GeometricIterator(int limit, int step, int current);

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