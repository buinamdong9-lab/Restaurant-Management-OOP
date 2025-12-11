#include "Food.h"
#include <iostream>
using namespace std;

Food::Food(const string& id, const string& n, double p, const string& cat)
    : MenuItem(id, n, p), category(cat) {
}

void Food::display() const {
    cout << "[Food] " << id << " | " << name << " - " << price
        << " | Category: " << category << endl;
}

string Food::getType() const {
    return "Food";
}
