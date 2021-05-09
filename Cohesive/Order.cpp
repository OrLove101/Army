#include "Order.hpp"
#include "Item.hpp"
#include "Category.hpp"
#include "Customer.hpp"

// Order::Order(Customer& customer, std::list<Item*>& lst) {
//     this->customer = &customer;
//     this->lst = &lst;

//     Order::globalId += 1;
//     this->id = Order::globalId;

//     std::list<Item*>::iterator it;

//     for ( it = lst.begin(); it != lst.end(); it++ ) {
//         (*it)->getOrdersList().push_back(this);
//     }

//     this->customer->addOrder(*this);
// }
Order::Order(Customer& customer, Item& item) {
    this->customer = &customer;
    this->lst->push_back(&item);

    Order::globalId += 1;
    this->id = Order::globalId;

    item.getOrdersList().push_back(this);

    this->customer->addOrder(*this);
}
Order::~Order() {
    // std::list<std::Item>::iterator it;

    // for ( it = lst->begin; it != lst->end(); it++ ) {
    //     *it->getOrderList->remove(this);
    // }
    // this->customer->getOrders()->remove(this);
}

std::list<Item*>& Order::getOrder() {
    return *this->lst;
}

void Order::addItem(Item& item) {
    this->lst->push_back(&item);
}
void Order::deleteItem(Item& item) {
    this->lst->remove(&item);
    //this->lst->erase(this->lst->find(item))
}

int Order::getId() {
    return this->id;
}

int Order::globalId = 0;