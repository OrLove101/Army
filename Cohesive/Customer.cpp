#include "Customer.hpp"
#include "Order.hpp"

Customer::Customer() {
    this->lst = new std::list<Order*>();

    Customer::globalId += 1;
    this->id = Customer::globalId;
}

Customer::~Customer() {}

std::list<Order*>& Customer::getOrders() {
    return *this->lst;
}

void Customer::addOrder(Order& order) const {
    this->lst->push_back(&order);
}

int Customer::getId() {
    return this->id;
}

int Customer::globalId = 0;