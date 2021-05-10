#include "ArrayIterator.hpp"

    template <typename Type>
    ArrayIterator<Type>::ArrayIterator(int limit, Type array[], int current) {
        if ( current < 0 || limit < 0 ) {
            throw InvalideStatement();
        }
        this->limit = limit;
        this->current = current;
        this->arrayPointer = array;
        this->first = 0;
    }

    template <typename Type>
    ArrayIterator<Type>::~ArrayIterator() {}

    template <typename Type>
    void ArrayIterator<Type>::next() {
        if ( over() ) {
            return;
        }
        current += 1;
    }

    template <typename Type>
    void ArrayIterator<Type>::previous() {
        if ( start() ) {
            return;
        }
        current -= 1;
    }

    template <typename Type>
    void ArrayIterator<Type>::operator++() { next(); }

    template <typename Type>
    void ArrayIterator<Type>::operator++(int) { operator++(); }

    template <typename Type>
    void ArrayIterator<Type>::operator--() { previous(); }

    template <typename Type>
    void ArrayIterator<Type>::operator--(int) { operator--(); }

    template <typename Type>
    bool ArrayIterator<Type>::over() { return current >= limit; }

    template <typename Type>
    bool ArrayIterator<Type>::start() { return current == first; }

    template <typename Type>
    Type ArrayIterator<Type>::value() { return arrayPointer[current]; }

    template <typename Type>
    Type ArrayIterator<Type>::operator*() { return value(); }
