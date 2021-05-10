#include "PrimeIterator.hpp"

int PrimeIterator::prime(int current) {
    int result, divisors, counter;
    
    for ( result = 2, divisors = 1, counter = 0; counter < current; result++ ) {
        for ( int j = 1; j < result; j++ ) {
            if ( result % j == 0 ) {
                divisors += 1;
            }
        }
        if ( divisors == 2 ) {
            counter += 1;
        }
        if ( counter == current ) {
            return result;
        }
        divisors = 1;
    }
}

    PrimeIterator::PrimeIterator(int limit, int current): limit(limit), first(current) {
        if ( current < 1 ) {
            throw InvalideStatement();
        }
        this->current = current;
    }

    void PrimeIterator::next() {
        if ( over() ) {
            return;
        }
        current += 1;
    }
    void PrimeIterator::previous() {
        if ( start() ) {
            return;
        }
        current -= 1;
    }
    void PrimeIterator::operator++() { next(); }

    void PrimeIterator::operator++(int) { operator++(); }

    void PrimeIterator::operator--() { previous(); }

    void PrimeIterator::operator--(int) { operator--(); }

    bool PrimeIterator::over() { return current >= limit; }

    bool PrimeIterator::start() { return current == first; }

    int PrimeIterator::value() { return prime(current); }

    int PrimeIterator::operator*() { return value(); }
