#pragma once
#include <iostream>
#include <string>
#include "Orderdemo.h"
using namespace std;

class Bill {
private:
    string billId;
    Order order;
    double taxRate;
    double serviceFee;
    double total;

public:
    Bill(string id = "", Order o = Order(), double tax = 0.1, double fee = 5000);

    void calcTotal();
    void print() const;

    double getTotal() const;
};
