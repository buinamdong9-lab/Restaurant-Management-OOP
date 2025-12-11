#define MAX_ORDERS 50

#include "Table.h"

Table::Table(int id) {
    tableId = id;
    isReserved = false;
    orderCount = 0;
}

void Table::reserve() {
    isReserved = true;
}

void Table::cancelReservation() {
    isReserved = false;
}

bool Table::addOrder(const Order& order) {
    if (orderCount >= MAX_ORDERS) {
        cout << "⚠ ERROR: Không thể thêm order. Bàn đã đủ số lượng order.\n";
        return false;
    }
    orders[orderCount] = order;
    orderCount++;
    return true;
}

bool Table::getStatus() const {
    return isReserved;
}

int Table::getOrderCount() const {
    return orderCount;
}

int Table::getId() const {
    return tableId;
}

void Table::print() const {
    cout << "\n===== Thong tin ban" << tableId << " =====\n";
    cout << "Trang thai: " << (isReserved ? "Da dat" : "Trong") << endl;
    cout << "so luong order " << orderCount << endl;

    if (orderCount == 0) {
        cout << "(Khong co order)\n";
    }
    else {
        cout << "--- Danh sach order ---\n";
        for (int i = 0; i < orderCount; i++) {
            orders[i].print();
        }
    }
    cout << "=============================\n";
}
