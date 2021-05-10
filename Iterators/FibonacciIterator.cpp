#include "FibonacciIterator.hpp"

int FibonacciIterator::fibonacci(int current) {
    int first = 0;
    int second = 1;
    int next;
    int flag = 1;

    if ( current == 1 || current == -1 ) {
        return 1;
    }
    if ( current > -2 && current < 2 ) {
        return current;
    }
    if (current < 0 ) {
        if ( current % 2 == 0 ) {
            flag = -1;
        }
        current *= -1;
    }

    for ( int i = 1; i < current; i++ ) {
        next = first + second;
        first = second;
        second = next;
    }
    return next*flag;
}

    FibonacciIterator::FibonacciIterator(int limit, int current): limit(limit), first(current), current(current) {}

    void FibonacciIterator::next() {
        if ( over() ) {
            return;
        }
        current += 1;
    }
    void FibonacciIterator::previous() {
        if ( start() ) {
            return;
        }
        current -= 1;
    }
    void FibonacciIterator::operator++() { next(); }

    void FibonacciIterator::operator++(int) { operator++(); }

    void FibonacciIterator::operator--() { previous(); }

    void FibonacciIterator::operator--(int) { operator--(); }

    bool FibonacciIterator::over() { return current >= limit; }

    bool FibonacciIterator::start() { return current == first; }

    int FibonacciIterator::value() { return fibonacci(current); }

    int FibonacciIterator::operator*() { return value(); }
