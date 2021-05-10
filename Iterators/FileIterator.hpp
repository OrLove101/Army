#ifndef FILEITERATOR_H
#define FILEITERATOR_H

#include <fstream>
#include <iostream>
#include <vector>

class InvalideStatement {};

template <typename Type>
class FileIterator {
private:
    int limit;
    int current;
    int first;
    int maxCurrent;
    std::ifstream file;
    std::vector<char>* lst;

public:
    FileIterator(int limit, const char* filename);

    ~FileIterator();

    void next();
    void previous();
    void operator++();

    void operator++(int);

    void operator--();

    void operator--(int);

    bool over();

    bool start();

    Type value();

    Type operator*();
};

#endif