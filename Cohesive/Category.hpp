#ifndef CATEGORY_H
#define CATEGORY_H

#include <iostream>
#include <list>

class Item;

class Category {
private:
    std::list<Item*>* lst;
    int id;

    static int globalId;

public:
    Category();
    ~Category();

    std::list<Item*>& getItems() const;

    void addItem(Item& item);
    void deleteItem(Item& item);
    int getId();
};

#endif