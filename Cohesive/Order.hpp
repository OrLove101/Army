#ifndef ORDER_H
#define ORDER_H

#include "Customer.hpp"
#include "Item.hpp"
#include <list>

class Customer;
class Item;

class Order {
private:
    Customer* customer;
    std::list<Item*>* lst;
    int id;

    static int globalId;
    static std::list<Order*>* objectsList;
public:
    Order(Customer* customer, Item* item);

    ~Order();

    void getOrder() const;

    void addItem(Item* item);
    void deleteItem(Item* item);

    int getId() const;

    static void getObjectsList();
};

std::ostream& operator<<(std::ostream& out, const Order& order);

#endif