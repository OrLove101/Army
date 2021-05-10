#include "ArithmeticIterator.hpp"

    ArithmeticIterator::ArithmeticIterator(int limit, int step, int current): limit(limit), 
        current(current), step(step), first(current) {}

    ArithmeticIterator::~ArithmeticIterator() {}

    void ArithmeticIterator::next() {
        if ( over() ) {
            return;
        }
        current += step;
    }

    void ArithmeticIterator::previous() {
        if ( start() ) {
            return;
        }
        current -= step;
    }

    void ArithmeticIterator::operator++() { next(); }

    void ArithmeticIterator::operator++(int) { operator++(); }

    void ArithmeticIterator::operator--() { previous(); }

    void ArithmeticIterator::operator--(int) { operator--(); }

    bool ArithmeticIterator::over() { return current >= limit; }

    bool ArithmeticIterator::start() { return current == first; }

    int ArithmeticIterator::value() { return current; }

    int ArithmeticIterator::operator*() { return value(); }