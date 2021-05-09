#ifndef ITEM_H
#define ITEM_H

#include "ListException.hpp"
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
    static std::list<Item*>* objectsList;
public:
    Item(const std::string& name, Category* category);
    ~Item();

    void getOrdersList();
    void addOrder(Order* order);
    const std::string& getName() const;

    int getId();

    static void getObjectsList();
};

std::ostream& operator<<(std::ostream& out, const Item& item);

#endif