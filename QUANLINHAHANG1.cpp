#include <iostream>
#include <limits>
#include "Restaurant.h"
using namespace std;

void clearScreen() {
    system("cls");
}

void pauseAndClear() {
    system("pause");
    system("cls");
}

void printMenu() {
    cout << "================== RESTAURANT SYSTEM ==================\n";
    cout << "1. Them mon vao menu\n";
    cout << "2. Xoa mon theo ID\n";
    cout << "3. Sua thong tin mon\n";
    cout << "4. Hien thi menu\n";
    cout << "5. Sap xep menu theo gia\n";
    cout << "6. Sap xep menu theo loai\n";
    cout << "7. Dat ban\n";
    cout << "8. Goi mon tai ban\n";
    cout << "9. Thanh toan ban\n";
    cout << "10. Luu menu ra file\n";
    cout << "11. Tai menu tu file\n";
    cout << "12. Xem doanh thu\n";
    cout << "0. Thoat\n";
    cout << "========================================================\n";
    cout << "Nhap lua chon: ";
}

int main() {
    Restaurant r;
    int choice;

    while (true) {
        clearScreen();
        printMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1: {
            clearScreen();
            cout << "1. Food\n2. Drink\nNhap loai: ";
            int t; cin >> t; cin.ignore();

            string id, name; double price;
            cout << "ID: "; getline(cin, id);
            cout << "Ten mon: "; getline(cin, name);
            cout << "Gia: "; cin >> price; cin.ignore();

            if (t == 1)
                r.addMenuItem(new Food(id, name, price, "Main"));
            else
                r.addMenuItem(new Drink(id, name, price, "M", true));

            cout << "✔ Da them mon!\n";
            pauseAndClear();
            break;
        }

        case 2:
            clearScreen();
            r.deleteMenuItemById();
            pauseAndClear();
            break;

        case 3:
            clearScreen();
            r.editMenuItem();
            pauseAndClear();
            break;

        case 4:
            clearScreen();
            r.showMenu();
            pauseAndClear();
            break;

        case 5:
            clearScreen();
            r.sortMenuByPrice();
            pauseAndClear();
            break;

        case 6:
            clearScreen();
            r.sortMenuByType();
            pauseAndClear();
            break;

        case 7:
            clearScreen();
            r.showTables();
            r.reserveTable();
            pauseAndClear();
            break;

        case 8:
            clearScreen();
            r.showMenu();
            r.addOrderToTable();
            pauseAndClear();
            break;

        case 9:
            clearScreen();
            r.checkoutTable();
            pauseAndClear();
            break;

        case 10:
            clearScreen();
            r.saveMenuToFile("menu.txt");
            cout << "✔ Da luu file menu!\n";
            pauseAndClear();
            break;

        case 11:
            clearScreen();
            r.loadMenuFromFile("menu.txt");
            pauseAndClear();
            break;

        case 12:
            clearScreen();
            r.showStatistics();   // ✔ Sửa tại đây!
            pauseAndClear();
            break;
            ;


        case 0:
            return 0;

        default:
            cout << "Nhap sai!\n";
            pauseAndClear();
        }
    }
}
