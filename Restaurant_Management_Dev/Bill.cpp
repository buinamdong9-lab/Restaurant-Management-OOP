#include "Bill.h"

Bill::Bill(string id, Order o, double tax, double fee) {
    billId = id;
    order = o;
    taxRate = tax;
    serviceFee = fee;
    total = 0;
}

void Bill::calcTotal() {
    double subTotal = order.calcTotal();
    double tax = subTotal * taxRate;

    total = subTotal + tax + serviceFee;
}

void Bill::print() const {
    cout << "\n======= HOA DON #" << billId << " =======" << endl;
    order.print();
    cout << "Thue (" << taxRate * 100 << "%): " << order.calcTotal() * taxRate << " VND\n";
    cout << "Phi dich vu: " << serviceFee << " VND\n";
    cout << "TONG TIEN: " << total << " VND\n";
    cout << "===============================\n";
}

double Bill::getTotal() const {
    return total;
}
