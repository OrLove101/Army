#ifndef CUSTOMER_H
#define CUSTOMER_H

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

    std::list<Order*>& getOrders();
    void addOrder(Order& order) const;

    int getId();
};
#endif