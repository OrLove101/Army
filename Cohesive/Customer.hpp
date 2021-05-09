#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Order.hpp"
#include <iostream>
#include <list>

class Order;

class Customer {
private:
    std::list<Order*>* lst;

    int id;
    static int globalId;
public:
    Customer();
    ~Customer();

    void getOrders();
    void addOrder(Order* order);

    int getId();
};
#endif