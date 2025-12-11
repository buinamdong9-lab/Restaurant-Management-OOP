#include "Drink.h"
#include <iostream>
using namespace std;

Drink::Drink(const string& id, const string& n, double p,
    const string& s, bool ice)
    : MenuItem(id, n, p), size(s), Hasice(ice) {
}

void Drink::display() const {
    cout << "[Drink] " << id << " | " << name << " - " << price
        << " | Size: " << size
        << " | Ice: " << (Hasice ? "Yes" : "No") << endl;
}

string Drink::getType() const {
    return "Drink";
}
