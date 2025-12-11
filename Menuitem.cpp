#include "MenuItem.h"

MenuItem::MenuItem(const string& id, const string& n, double p)
    : id(id), name(n), price(p) {
}

string MenuItem::getId() const {
    return id;
}

void MenuItem::setId(const string& newId) {
    id = newId;
}

string MenuItem::getName() const {
    return name;
}

double MenuItem::getPrice() const {
    return price;
}

void MenuItem::setPrice(double p) {
    price = p;
}
