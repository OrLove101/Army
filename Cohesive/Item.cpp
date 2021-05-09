#include "Item.hpp"
#include "Category.hpp"
#include "Order.hpp"

Item::Item(Category& category) {
    this->category = &category;
    this->category->addItem(*this);
    this->lst = new std::list<Order*>();
    Item::globalId += 1;
    this->id = Item::globalId;
}

Item::~Item() {
    // this->category->deleteItem(this);
}

std::list<Order*>& Item::getOrdersList() {
    return *this->lst;
}

int Item::getId() {
    return this->id;
}

int Item::globalId = 0;