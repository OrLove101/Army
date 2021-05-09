#include "Category.hpp"
#include "Item.hpp"

Category::Category() {
    this->lst = new std::list<Item*>();
    Category::globalId += 1;
    this->id = Category::globalId;
}
Category::~Category() {}

std::list<Item*>& Category::getItems() const {
    return *this->lst;
}

void Category::addItem(Item& item) {
    this->lst->push_back(&item);
}
void Category::deleteItem(Item& item) {
    this->lst->remove(&item);
}
int Category::getId() {
    return this->id;
}

int Category::globalId = 0;



