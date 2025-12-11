#include "Customer.h"

Customer::Customer(const string& n, const string& p)
    : name(n), phone(p) {
}

void Customer::setInfo(const string& n, const string& p) {
    name = n;
    phone = p;
}

string Customer::getName() const {
    return name;
}

string Customer::getPhone() const {
    return phone;
}

void Customer::input() {
    cout << "Nhap ten khach: ";
    getline(cin >> ws, name);
    cout << "Nhap so dien thoai: ";
    getline(cin >> ws, phone);
}

void Customer::display() const {
    cout << "Khach: " << name << " | SDT: " << phone;
}
