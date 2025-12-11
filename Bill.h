#pragma once
#include <iostream>
#include "OrderItem.h"
#include "Customer.h"
using namespace std;

const int MAX_ORDER_ITEMS = 50;

class Bill {
private:
    OrderItem items[MAX_ORDER_ITEMS];
    int itemCount;
    Customer customer;
    double taxRate;     // vd: 0.1 = 10%
    double serviceFee;  // so tien co dinh
public:
    Bill(double tax = 0.1, double fee = 0.0);

    void setCustomer(const Customer& c);
    Customer getCustomer() const;

    bool addItem(MenuItem* item, int quantity);
    bool updateItem(int index, int quantity);
    bool removeItem(int index);

    double calcSubtotal() const;
    double calcTotal() const;

    void display() const;

    // nạp chồng toán tử <<
    friend ostream& operator<<(ostream& os, const Bill& b);
};
