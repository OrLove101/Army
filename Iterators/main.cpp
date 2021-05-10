#include <iostream>
#include <fstream>
// #include "ArrayIterator.cpp"
#include "FileIterator.cpp"
// #include "ArithmeticIterator.hpp"
// #include "GeometricIterator.hpp"
// #include "FactorialIterator.hpp"
// #include "FibonacciIterator.hpp"
// #include "PrimeIterator.hpp"



// using namespace std;

int main() {
    // int array[] = {1, 2, 3, 4, 5};
    // ArrayIterator <int>iter(4, array, 1);
    FileIterator <char> iter(3, "text.txt");
    // ArithmeticIterator iter(10, 1, 1);
    // GeometricIterator iter(20, 2, 1);
    // FactorialIterator iter(5, 1);
    // FibonacciIterator iter(10, 1);
    // PrimeIterator iter(10, 1);

    for ( ; !iter.over(); iter++ ) {
        std::cout << *iter << std::endl;
    }
    std::cout << *iter << std::endl;
    //iter--;
    //std::cout << *iter << std::endl;
    for ( ; !iter.start(); iter-- ) {
        std::cout << *iter << std::endl;
    }
    std::cout << *iter << std::endl;

    return 0;
}