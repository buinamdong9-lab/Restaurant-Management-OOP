#include "OrderItem.h"

OrderItem::OrderItem(MenuItem* it, int q)
    : item(it), quantity(q) {
}

void OrderItem::setItem(MenuItem* it) {
    item = it;
}

void OrderItem::setQuantity(int q) {
    quantity = q;
}

MenuItem* OrderItem::getItem() const {
    return item;
}

int OrderItem::getQuantity() const {
    return quantity;
}

double OrderItem::getTotal() const {
    if (!item) return 0.0;
    return item->getPrice() * quantity;
}

void OrderItem::display() const {
    if (item) {
        cout << "- " << item->getName()
            << " x" << quantity
            << " = " << getTotal() << endl;
    }
}
