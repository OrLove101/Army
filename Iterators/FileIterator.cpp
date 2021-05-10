#include "FileIterator.hpp"

template <typename Type>
FileIterator<Type>::FileIterator(int limit, const char* filename) {
    this->lst = new std::vector<char>();
    if ( limit <= 0 ) {
        throw InvalideStatement();
    }
    this->limit = limit-1;
    this->current = 0;
    this->maxCurrent = 0;
    this->first = 0;
    this->file.open(filename);
    this->lst->push_back(file.get());
}

template <typename Type>
FileIterator<Type>::~FileIterator() {
    file.close();
}

template <typename Type>
void FileIterator<Type>::next() {
    if ( over() ) {
        return;
    }
    current += 1;
    maxCurrent += 1;
    if ( maxCurrent <= limit ) {
        this->lst->push_back(file.get());
    }
}

template <typename Type>
void FileIterator<Type>::previous() {
    if ( start() ) {
        return;
    }
    current -= 1;
}

template <typename Type>
void FileIterator<Type>::operator++() { next(); }

template <typename Type>
void FileIterator<Type>::operator++(int) { operator++(); }

template <typename Type>
void FileIterator<Type>::operator--() { previous(); }

template <typename Type>
void FileIterator<Type>::operator--(int) { operator--(); }

template <typename Type>
bool FileIterator<Type>::over() { return current >= limit; }

template <typename Type>
bool FileIterator<Type>::start() { return current == first; }

template <typename Type>
Type FileIterator<Type>::value() { return (*this->lst)[current]; }

template <typename Type>
Type FileIterator<Type>::operator*() { return value(); }