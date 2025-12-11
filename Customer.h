#pragma once
#include <iostream>
#include <string>
using namespace std;

class Customer {
private:
    string name;
    string phone;
public:
    Customer(const string& n = "", const string& p = "");

    void setInfo(const string& n, const string& p);
    string getName() const;
    string getPhone() const;

    void input();
    void display() const;
};
