#ifndef CATEGORY_H
#define CATEGORY_H

#include "Item.hpp"
#include <iostream>
#include <list>

class Item;

class Category {
private:
    std::string name;
    std::list<Item*>* lst;
    int id;

    static int globalId;
    static std::list<Category*>* objectsList;

public:
    Category(const std::string& name);
    ~Category();

    void getItems() const;

    void addItem(Item* item);
    void deleteItem(Item* item);
    int getId() const;
    const std::string& getName() const;

    static void getObjectsList();
};

std::ostream& operator<<(std::ostream& out, const Category& category);

#endif