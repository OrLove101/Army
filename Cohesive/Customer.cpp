#include "Customer.hpp"

Customer::Customer(const std::string& name) {
    this->name = name;
    this->lst = new std::list<Order*>();

    Customer::globalId += 1;
    Customer::objectsList->push_back(this);
    this->id = Customer::globalId;
}

Customer::~Customer() {}

void Customer::getOrders() {
    if ( this->lst->empty() ) {
        throw ListIsEmpty();
    }
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

const std::string& Customer::getName() const {
    return this->name;
}

std::ostream& operator<<(std::ostream& out, const Customer& customer) {
    out << customer.getName();

    return out;
}

std::list<Customer*>* Customer::objectsList = new std::list<Customer*>();

void Customer::getObjectsList() {
    std::list<Customer*>::iterator it;

    for ( it = Customer::objectsList->begin(); it != Customer::objectsList->end(); it++ ) {
        std::cout << *(*it) << std::endl;
    }
}

int Customer::globalId = 0;