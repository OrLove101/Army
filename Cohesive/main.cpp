#include "Category.hpp"
#include "Category.cpp"//???
#include "Item.hpp"
#include "Item.cpp"//???
#include "Order.hpp"
#include "Order.cpp"//???
#include "Customer.hpp"
#include "Customer.cpp"//???
#include <iostream>

int main() {
    Category* cups = new Category();
    Item* redCup = new Item(*cups);
    Customer* grisha = new Customer();
    Order* order = new Order(*grisha, *redCup);

    Category* phones = new Category();
    Item* iphone = new Item(*phones);
    // order->addItem(*iphone);

    // grisha->getOrders();

    std::cout << "cups - " << cups->getId() << std::endl;

    return 0;
}