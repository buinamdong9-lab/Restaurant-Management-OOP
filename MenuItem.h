#pragma once
#include <iostream>
#include <string>
using namespace std;

class MenuItem {
protected:
    string id;      // Thêm ID
    string name;
    double price;

public:
    MenuItem(const string& id = "", const string& n = "", double p = 0.0);
    virtual ~MenuItem() {}

    // Getter - Setter
    string getId() const;
    void setId(const string& newId);

    string getName() const;
    double getPrice() const;
    void setPrice(double p);

    virtual void display() const = 0;
    virtual string getType() const = 0;
};
