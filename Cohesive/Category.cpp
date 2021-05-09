#include "Category.hpp"

Category::Category(const std::string& name) {
    this->name = name;
    this->lst = new std::list<Item*>();

    Category::globalId += 1;
    this->id = Category::globalId;
}
Category::~Category() {}

void Category::getItems() const {
    std::list<Item*>::iterator it;

    for ( it = this->lst->begin(); it != this->lst->end(); it++ ) {
        std::cout << *(*it) << std::endl;
    }
}

void Category::addItem(Item* item) {
    this->lst->push_back(item);
}
void Category::deleteItem(Item* item) {
    this->lst->remove(item);
}
int Category::getId() const {
    return this->id;
}

const std::string& Category::getName() const {
    return this->name;
}

int Category::globalId = 0;

std::ostream& operator<<(std::ostream& out, const Category& category) {
    out << category.getName();

    return out;
}
