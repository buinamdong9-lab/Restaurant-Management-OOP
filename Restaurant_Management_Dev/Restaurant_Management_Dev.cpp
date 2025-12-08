#include <iostream>
#include "Table.h"
#include "Bill.h"
using namespace std;

int main() {

    Table t(5);
    t.reserve();

    // Order giả lập
    Order o1("OD01", 120000);
    Order o2("OD02", 50000);

    t.addOrder(o1);
    t.addOrder(o2);

    t.print();

    // Tạo hóa đơn cho Order đầu tiên
    Bill bill("B001", o1, 0.1, 5000);
    bill.calcTotal();
    bill.print();

    return 0;
}
