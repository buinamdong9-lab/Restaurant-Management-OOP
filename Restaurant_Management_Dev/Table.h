#pragma once
#include "Orderdemo.h"
#include <iostream>
#include <string>
using namespace std;

class Table {
private:
	int tableId;
	bool isReserved;
	Order orders[50];
	int orderCount; // FIX: Changed from 'OrderCount' to 'orderCount' to match implementation
public:
    Table(int id = 0);
    void reserve();
    void cancelReservation();
    bool addOrder(const Order& order);
    bool getStatus() const; // FIX: Add 'const' to match implementation
    int getOrderCount() const; // FIX: Add 'const' to match implementation
    int getId() const; // FIX: Add 'const' to match implementation
    void print() const; // FIX: Add 'const' to match implementation
};