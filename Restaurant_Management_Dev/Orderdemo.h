#pragma once
#include <iostream>
#include <string>
using namespace std;

class Order {
private:
    string orderId;
    double totalPrice; // tam tinh test

public:
    Order(string id = "", double price = 0) {
        orderId = id;
        totalPrice = price;
    }

    double calcTotal() const {
        return totalPrice;
    }

    string getId() const {
        return orderId;
    }

    void print() const {
        cout << "   Order ID: " << orderId << " | Total: " << totalPrice << " VND\n";
    }
};
