#pragma once
#include "MenuItem.h"

class Food : public MenuItem {
private:
    string category;

public:
    Food(const string& id = "", const string& n = "", double p = 0.0,
        const string& cat = "Main");

    void display() const override;
    string getType() const override;
};
