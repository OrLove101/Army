#include "Category.hpp"

Category::Category(const std::string& name) {
    this->name = name;
    this->lst = new std::list<Item*>();

    Category::globalId += 1;
    Category::objectsList->push_back(this);

    this->id = Category::globalId;
}
Category::~Category() {}

void Category::getItems() const {
    if ( this->lst->empty() ) {
        throw ListIsEmpty();
    }
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
std::list<Category*>* Category::objectsList = new std::list<Category*>();

void Category::getObjectsList() {
    std::list<Category*>::iterator it;

    for ( it = Category::objectsList->begin(); it != Category::objectsList->end(); it++ ) {
        std::cout << *(*it) << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Category& category) {
    out << category.getName();

    return out;
}
