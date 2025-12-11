#pragma once
#include "Bill.h"
#include "Customer.h"

class Table {
private:
    int id;
    bool occupied;
    Bill bill;
public:
    Table(int i = 0);

    int getId() const;
    bool isOccupied() const;

    void reserve(const Customer& c);
    void release();

    Bill& getBill();
    void display() const;
};
