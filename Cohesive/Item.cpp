#include "Item.hpp"

Item::Item(const std::string& name, Category* category) {
    this->name = name;
    this->lst = new std::list<Order*>();
    this->category = category;
    this->category->addItem(this);

    Item::globalId += 1;
    Item::objectsList->push_back(this);
    this->id = Item::globalId;
}

Item::~Item() {}

void Item::getOrdersList() {
    if ( this->lst->empty() ) {
        throw ListIsEmpty();
    }
    std::list<Order*>::iterator it;

    for ( it = this->lst->begin(); it != this->lst->end(); it++ ) {
        std::cout << *(*it) << std::endl;
    }
}

void Item::addOrder(Order* order) {
    this->lst->push_back(order);
}

const std::string& Item::getName() const {
    return this->name;
}

int Item::getId() {
    return this->id;
}

std::ostream& operator<<(std::ostream& out, const Item& item) {
    out << item.getName();

    return out;
}

void Item::getObjectsList() {
    std::list<Item*>::iterator it;

    for ( it = Item::objectsList->begin(); it != Item::objectsList->end(); it++ ) {
        std::cout << *(*it) << std::endl;
    }
}

std::list<Item*>* Item::objectsList = new std::list<Item*>();

int Item::globalId = 0;