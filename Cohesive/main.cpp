#include <iostream>
#include "Customer.hpp"
#include "Customer.cpp"
#include "Order.hpp"
#include "Order.cpp"
#include "Item.hpp"
#include "Item.cpp"
#include "Category.hpp"
#include "Category.cpp"

int main() {
    Category* cups = new Category("cups");
    Item* redCup = new Item("Red cup", cups);
    Item* blueCup = new Item("Blue cup", cups);
    Item* greenCup = new Item("Green cup", cups);
    Customer* gosha = new Customer();
    Order* order = new Order(gosha, redCup);
    Order* order1 = new Order(gosha, redCup);

    order->addItem(blueCup);
    order1->addItem(greenCup);

    // order->getOrder();

    redCup->getOrdersList();

    // cups->getItems();

    return 0;
}