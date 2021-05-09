#ifndef ITEM_H
#define ITEM_H

#include "Category.hpp"
#include "Order.hpp"
#include <iostream>
#include <list>

class Category;
class Order;

class Item {
private:
    std::string name;
    Category* category;
    std::list<Order*>* lst;
    int id;

    static int globalId;
public:
    Item(const std::string& name, Category* category);
    ~Item();

    void getOrdersList();
    void addOrder(Order* order);
    const std::string& getName() const;

    int getId();
};

std::ostream& operator<<(std::ostream& out, const Item& item);

#endif