#include "Bill.h"

Bill::Bill(double tax, double fee)
    : itemCount(0), taxRate(tax), serviceFee(fee) {
}

void Bill::setCustomer(const Customer& c) {
    customer = c;
}

Customer Bill::getCustomer() const {
    return customer;
}

bool Bill::addItem(MenuItem* item, int quantity) {
    if (!item || itemCount >= MAX_ORDER_ITEMS || quantity <= 0)
        return false;
    items[itemCount].setItem(item);
    items[itemCount].setQuantity(quantity);
    itemCount++;
    return true;
}

bool Bill::updateItem(int index, int quantity) {
    if (index < 0 || index >= itemCount || quantity <= 0)
        return false;
    items[index].setQuantity(quantity);
    return true;
}

bool Bill::removeItem(int index) {
    if (index < 0 || index >= itemCount)
        return false;
    for (int i = index; i < itemCount - 1; ++i) {
        items[i] = items[i + 1];
    }
    itemCount--;
    return true;
}

double Bill::calcSubtotal() const {
    double sum = 0.0;
    for (int i = 0; i < itemCount; ++i) {
        sum += items[i].getTotal();
    }
    return sum;
}

double Bill::calcTotal() const {
    double subtotal = calcSubtotal();
    double tax = subtotal * taxRate;
    return subtotal + tax + serviceFee;
}

void Bill::display() const {
    cout << "===== HOA DON =====" << endl;
    customer.display();
    cout << endl;
    for (int i = 0; i < itemCount; ++i) {
        items[i].display();
    }
    double subtotal = calcSubtotal();
    double tax = subtotal * taxRate;
    cout << "-------------------" << endl;
    cout << "Tam tinh: " << subtotal << endl;
    cout << "Thue (" << taxRate * 100 << "%): " << tax << endl;
    cout << "Phi dich vu: " << serviceFee << endl;
    cout << "Tong tien: " << calcTotal() << endl;
    cout << "===================" << endl;
}

ostream& operator<<(ostream& os, const Bill& b) {
    os << "HOA DON - ";
    os << b.customer.getName() << " (" << b.customer.getPhone() << ")\n";
    for (int i = 0; i < b.itemCount; ++i) {
        MenuItem* item = b.items[i].getItem();
        if (item) {
            os << item->getName()
                << " x" << b.items[i].getQuantity()
                << " = " << b.items[i].getTotal() << "\n";
        }
    }
    double subtotal = b.calcSubtotal();
    double tax = subtotal * b.taxRate;
    os << "Tam tinh: " << subtotal << "\n";
    os << "Thue: " << tax << "\n";
    os << "Phi dich vu: " << b.serviceFee << "\n";
    os << "Tong: " << b.calcTotal() << "\n";
    os << "----------------------\n";
    return os;
}
