#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <list>

class Customer;
class Item;

class Order {
private:
    const Customer* customer;
    std::list<Item*>* lst;
    int id;

    static int globalId;
public:
    // Order(Customer& customer, std::list<Item*>& lst);
    Order(Customer& customer, Item& item);

    ~Order();

    std::list<Item*>& getOrder();

    void addItem(Item& item);
    void deleteItem(Item& item);

    int getId();
};

#endif