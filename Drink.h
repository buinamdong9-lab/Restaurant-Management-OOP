#pragma once
#include "MenuItem.h"

class Drink : public MenuItem {
private:
    string size;
    bool Hasice;

public:
    Drink(const string& id = "", const string& n = "", double p = 0.0,
        const string& s = "M", bool ice = true);

    void display() const override;
    string getType() const override;
};
