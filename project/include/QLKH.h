#include"KhachHang.h"
#include<string>
#include<iostream>

using namespace std;

void QLKHmenu() {
    KhachHang kh; 
    int choice;
    kh.docDSCus();
    do {
        cout << "======================== MENU ========================" << endl;
        cout << "1. Them khach hang"  << endl;
        cout << "2. Xoa khach hang" << endl;
        cout << "3. Sua khach hang" << endl;
        cout << "4. Hien thi danh sach khach hang" << endl;
        cout << "5. Tim kiem khach hang" << endl;
        cout << "6. Luu danh sach khach hang" << endl;
        cout << "0. Thoat" << endl;
        cout << "=====================================================" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch (choice) {
        case 1:
            kh.themCus();
            break;
        case 2:
            kh.xoaCus();
            break;
        case 3:
            kh.suaCus();
            break;
        case 4:
             kh.hienThiDSCus();
            break;
        case 5:
            kh.timKiemCus();
            break;
        case 6:
            kh.luuDSCus();
            break;
        case 0:
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
            break;
        }
    } while (choice != 0);
}
