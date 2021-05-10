    #include "FactorialIterator.hpp"

    int FactorialIterator::factorial(int n) {
        if ( n < 2 ) {
            return 1;
        }
        return n * factorial(n-1);
    }

    FactorialIterator::FactorialIterator(int limit, int current): limit(limit), first(current) {
            if ( current < 0 ) {
                throw InvalideStatement();
            }
            this->current = current;
    }

    void FactorialIterator::next() {
        if ( over() ) {
            return;
        }
        current += 1;
    }
    void FactorialIterator::previous() {
        if ( start() ) {
            return;
        }
        current -= 1;
    }
    void FactorialIterator::operator++() { next(); }

    void FactorialIterator::operator++(int) { operator++(); }

    void FactorialIterator::operator--() { previous(); }

    void FactorialIterator::operator--(int) { operator--(); }

    bool FactorialIterator::over() { return current >= limit; }

    bool FactorialIterator::start() { return current == first; }

    int FactorialIterator::value() { return factorial(current); }

    int FactorialIterator::operator*() { return value(); }
