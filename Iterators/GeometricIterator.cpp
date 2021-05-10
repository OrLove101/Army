    #include "GeometricIterator.hpp"

    GeometricIterator::GeometricIterator(int limit, int step, int current): limit(limit), 
        current(current), step(step), first(current) {}

    void GeometricIterator::next() {
        if ( over() ) {
            return;
        }
        current *= step;
    }

    void GeometricIterator::previous() {
        if ( start() ) {
            return;
        }
        current /= step;
    }

    void GeometricIterator::operator++() { next(); }

    void GeometricIterator::operator++(int) { operator++(); }

    void GeometricIterator::operator--() { previous(); }

    void GeometricIterator::operator--(int) { operator--(); }

    bool GeometricIterator::over() { return current >= limit; }

    bool GeometricIterator::start() { return current == first; }

    int GeometricIterator::value() { return current; }

    int GeometricIterator::operator*() { return value(); }
