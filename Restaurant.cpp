#include "Restaurant.h"
#include <iostream>
#include <limits>
using namespace std;

Restaurant::Restaurant() : menuCount(0), tableCount(5), revenue(0.0) {
    for (int i = 0; i < tableCount; ++i)
        tables[i] = Table(i + 1);
}

Restaurant::~Restaurant() {
    for (int i = 0; i < menuCount; ++i)
        delete menu[i];
}

// ====================== MENU =========================

void Restaurant::showMenu() const {
    cout << "======= MENU =======" << endl;
    if (menuCount == 0) {
        cout << "(Menu rong)\n";
        return;
    }
    for (int i = 0; i < menuCount; ++i) {
        cout << i + 1 << ". ";
        menu[i]->display();
    }
    cout << "====================" << endl;
}

bool Restaurant::addMenuItem(MenuItem* item) {
    if (!item || menuCount >= MAX_MENU_ITEMS)
        return false;
    menu[menuCount++] = item;
    return true;
}

int Restaurant::findMenuItemById(const string& id) const {
    for (int i = 0; i < menuCount; ++i)
        if (menu[i]->getId() == id)
            return i;
    return -1;
}

void Restaurant::deleteMenuItemById() {
    string id;
    cout << "Nhap ID muon xoa: ";
    getline(cin, id);

    int idx = findMenuItemById(id);
    if (idx == -1) {
        cout << "Khong tim thay mon!\n";
        return;
    }

    delete menu[idx];
    for (int i = idx; i < menuCount - 1; ++i)
        menu[i] = menu[i + 1];

    menuCount--;
    cout << "✔ Da xoa mon!\n";
}

void Restaurant::editMenuItem() {
    string id;
    cout << "Nhap ID mon muon sua: ";
    getline(cin, id);

    int idx = findMenuItemById(id);
    if (idx == -1) {
        cout << "ID khong ton tai!\n";
        return;
    }

    MenuItem* item = menu[idx];

    cout << "1. Sua gia\n";
    cout << "2. Sua thuoc tinh rieng (category/size)\n";
    cout << "Nhap lua chon: ";
    int c;
    cin >> c;
    cin.ignore();

    if (c == 1) {
        double p;
        cout << "Gia moi: ";
        cin >> p;
        item->setPrice(p);
    }
    else if (c == 2) {
        if (Food* f = dynamic_cast<Food*>(item)) {
            string cat;
            cout << "Category moi: ";
            getline(cin, cat);
            *f = Food(f->getId(), f->getName(), f->getPrice(), cat);
        }
        else if (Drink* d = dynamic_cast<Drink*>(item)) {
            string size;
            bool ice;
            cout << "Size moi (S/M/L): ";
            cin >> size;
            cout << "Da (1=Yes, 0=No): ";
            cin >> ice;
            *d = Drink(d->getId(), d->getName(), d->getPrice(), size, ice);
        }
    }

    cout << "✔ Da cap nhat mon!\n";
}

// ====================== TABLE =========================

void Restaurant::showTables() const {
    cout << "===== DANH SACH BAN =====\n";

    int freeCount = 0;

    for (int i = 0; i < tableCount; ++i) {
        tables[i].display();
        if (!tables[i].isOccupied())
            freeCount++;
    }

    cout << "==========================\n";
    cout << "So ban trong: " << freeCount << " / " << tableCount << endl;
}


void Restaurant::reserveTable() {
    int id;
    cout << "Nhap so ban muon dat: ";
    cin >> id;
    cin.ignore();

    int idx = -1;
    for (int i = 0; i < tableCount; ++i)
        if (tables[i].getId() == id) idx = i;

    if (idx == -1) { cout << "Ban khong ton tai!\n"; return; }
    if (tables[idx].isOccupied()) { cout << "Ban da co khach!\n"; return; }

    Customer c;
    c.input();
    tables[idx].reserve(c);

    cout << "✔ Da dat ban!\n";
}

void Restaurant::addOrderToTable() {
    int id;
    cout << "Nhap so ban: ";
    cin >> id;
    cin.ignore();

    int idx = -1;
    for (int i = 0; i < tableCount; ++i)
        if (tables[i].getId() == id) idx = i;

    if (idx == -1) { cout << "Ban khong ton tai!\n"; return; }
    if (!tables[idx].isOccupied()) { cout << "Ban dang trong!\n"; return; }

    string itemId;
    cout << "Nhap ID mon: ";
    getline(cin, itemId);

    int mIdx = findMenuItemById(itemId);
    if (mIdx == -1) {
        cout << "Mon khong ton tai!\n";
        return;
    }

    int quantity;
    cout << "So luong: ";
    cin >> quantity;

    tables[idx].getBill().addItem(menu[mIdx], quantity);

    cout << "✔ Da them mon!\n";
}

void Restaurant::checkoutTable() {
    int id;
    cout << "Nhap so ban thanh toan: ";
    cin >> id;
    cin.ignore();

    int idx = -1;
    for (int i = 0; i < tableCount; ++i)
        if (tables[i].getId() == id) idx = i;

    if (idx == -1) { cout << "Ban khong ton tai!\n"; return; }
    if (!tables[idx].isOccupied()) { cout << "Ban dang trong!\n"; return; }

    Bill& b = tables[idx].getBill();
    b.display();

    revenue += b.calcTotal();

    string filename = "bill_table" + to_string(id) + ".txt";
    ofstream out(filename);
    out << b;
    out.close();

    tables[idx].release();
    cout << "✔ Da thanh toan!\n";
}

// ====================== FILE =========================

void Restaurant::saveMenuToFile(const string& filename) const {
    ofstream out(filename);

    for (int i = 0; i < menuCount; ++i) {
        out << menu[i]->getType() << "\n";
        out << menu[i]->getId() << "\n";
        out << menu[i]->getName() << "\n";
        out << menu[i]->getPrice() << "\n";
    }
}

void Restaurant::loadMenuFromFile(const string& filename) {
    ifstream in(filename);

    if (!in) {
        cout << "Khong mo duoc file!\n";
        return;
    }

    // Xóa menu cũ để tránh nhân bản
    for (int i = 0; i < menuCount; ++i)
        delete menu[i];
    menuCount = 0;

    string type, id, name;
    double price;

    while (getline(in, type)) {
        if (type.empty()) continue;

        getline(in, id);
        getline(in, name);
        in >> price;
        in.ignore();

        if (type == "Food")
            addMenuItem(new Food(id, name, price, "Main"));
        else if (type == "Drink")
            addMenuItem(new Drink(id, name, price, "M", true));
    }

    cout << "✔ Da tai menu tu file!\n";
}

// ====================== SORT =========================

void Restaurant::sortMenuByPrice() {
    for (int i = 0; i < menuCount - 1; ++i)
        for (int j = i + 1; j < menuCount; ++j)
            if (menu[i]->getPrice() > menu[j]->getPrice())
                swap(menu[i], menu[j]);

    cout << "✔ Da sap xep theo gia.\n";
}

void Restaurant::sortMenuByType() {
    for (int i = 0; i < menuCount - 1; ++i)
        for (int j = i + 1; j < menuCount; ++j) {
            bool isFood_i = menu[i]->getType() == "Food";
            bool isFood_j = menu[j]->getType() == "Food";
            if (!isFood_i && isFood_j)
                swap(menu[i], menu[j]);
        }
    cout << "✔ Da sap xep theo loai.\n";
}

void Restaurant::showStatistics() const {
    cout << "Tong doanh thu: " << revenue << endl;
}
