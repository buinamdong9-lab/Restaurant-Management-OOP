#pragma once
#include "MenuItem.h"
#include "Food.h"
#include "Drink.h"
#include "Table.h"
#include <fstream>

const int MAX_MENU_ITEMS = 100;
const int MAX_TABLES = 20;

class Restaurant {
private:
    MenuItem* menu[MAX_MENU_ITEMS];
    int menuCount;

    Table tables[MAX_TABLES];
    int tableCount;

    double revenue;

public:
    Restaurant();
    ~Restaurant();

    // MENU
    void showMenu() const;
    bool addMenuItem(MenuItem* item);

    void editMenuItem();       // sửa giá, size, category
    void deleteMenuItemById(); // xóa theo ID

    int  findMenuItemById(const string& id) const;

    // TABLE
    void showTables() const;
    void reserveTable();
    void addOrderToTable();
    void checkoutTable();

    // FILE I/O
    void saveMenuToFile(const string& filename) const;
    void loadMenuFromFile(const string& filename);

    void appendBillToFile(const string& filename, const Bill& bill) const;



    // STATISTICS
    void sortMenuByPrice();
    void sortMenuByType();
    void showStatistics() const;
};
