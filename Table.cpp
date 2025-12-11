#include "Table.h"
#include <iostream>
using namespace std;

Table::Table(int i) : id(i), occupied(false), bill(0.1, 0.0) {}

int Table::getId() const {
    return id;
}

bool Table::isOccupied() const {
    return occupied;
}

void Table::reserve(const Customer& c) {
    occupied = true;
    bill = Bill(0.1, 0.0);
    bill.setCustomer(c);
}

void Table::release() {
    occupied = false;
}

Bill& Table::getBill() {
    return bill;
}

void Table::display() const {
    cout << "Ban " << id << " - "
        << (occupied ? "Dang co khach" : "Trong") << endl;
}
