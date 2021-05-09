#include "Customer.hpp"

Customer::Customer() {
    this->lst = new std::list<Order*>();

    Customer::globalId += 1;
    this->id = Customer::globalId;
}

Customer::~Customer() {}

void Customer::getOrders() {
    std::list<Order*>::iterator it;

    for ( it = this->lst->begin(); it != this->lst->end(); it++ ) {
        std::cout << *(*it) << std::endl;
    }
}

void Customer::addOrder(Order* order) {
    this->lst->push_back(order);
}

int Customer::getId() {
    return this->id;
}

int Customer::globalId = 0;