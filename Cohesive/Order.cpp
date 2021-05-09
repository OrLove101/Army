#include "Order.hpp"

Order::Order(Customer* customer, Item* item) {
    this->customer = customer;
    this->lst = new std::list<Item*>();
    this->lst->push_back(item);

    Order::globalId += 1;
    this->id = Order::globalId;

    item->addOrder(this);

    customer->addOrder(this);
}
Order::~Order() { }

void Order::getOrder() const {
    std::list<Item*>::iterator it;

    for ( it = this->lst->begin(); it != this->lst->end(); it++ ) {
        std::cout << *(*it) << std::endl;
    }
}

void Order::addItem(Item* item) {
    this->lst->push_back(item);
}
void Order::deleteItem(Item* item) {
    this->lst->remove(item);
    //this->lst->erase(this->lst->find(item))
}

std::ostream& operator<<(std::ostream& out, const Order& order) {
    order.getOrder();
    out << " - is order " << order.getId();

    return out;
}

int Order::getId() const {
    return this->id;
}

int Order::globalId = 0;