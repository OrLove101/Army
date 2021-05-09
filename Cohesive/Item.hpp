#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <list>

class Category;
class Order;

class Item {
private:
    Category* category;
    std::list<Order*>* lst;
    int id;

    static int globalId;
public:
    Item(Category& category);
    ~Item();

    std::list<Order*>& getOrdersList();

    int getId();
};

#endif