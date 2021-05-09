#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "ListException.hpp"
#include "Order.hpp"
#include <iostream>
#include <list>

class Order;

class Customer {
private:
    std::list<Order*>* lst;
    std::string name;

    int id;
    static int globalId;
    static std::list<Customer*>* objectsList;
public:
    Customer(const std::string& name);
    ~Customer();

    void getOrders();
    void addOrder(Order* order);

    int getId();
    const std::string& getName() const;

    static void getObjectsList();
};

std::ostream& operator<<(std::ostream& out, const Customer& customer);

#endif