#pragma once
#include <iostream>
#include "MenuItem.h"
using namespace std;

class OrderItem {
private:
    MenuItem* item;   // không sở hữu, chỉ trỏ đến món trong menu
    int quantity;
public:
    OrderItem(MenuItem* it = nullptr, int q = 0);

    void setItem(MenuItem* it);
    void setQuantity(int q);

    MenuItem* getItem() const;
    int getQuantity() const;

    double getTotal() const;
    void display() const;
};
