#ifndef QLDT_H
#define QLDT_H
#include <string>
#include "DoanhThu.h"
#include "DonHang.h"
#include "NhaCungCap.h"
#include <iostream>

using namespace std;

void QLDTmenu() {
    DonHang dh;
    dh.docDonHang();
    NhaCungCap ncc;
    ncc.docNCC();
    int chon;
    string filename = "data/DonHang.txt";
    string filePath = "data/nhacungcap.txt";
    string filePath1 = "data/sanpham.txt";
    do {
        cout << "======================== MENU ========================" << endl;
        cout << "1. Tinh tong tien 'Giao hang thanh cong'" << endl;
        cout << "2. Tinh tong tien 'Nha cung cap'" << endl; 
        cout << "3. Tinh tong tien 'San pham dang co'" << endl;
        cout << "0. Thoat" << endl;
        cout << "=====================================================" << endl;
        cout << "Nhap lua chon: ";
        cin >> chon;
        switch (chon) {
            case 1: {
                long long tongTien = DoanhThu::tinhTongTienGiaoHangThanhCong(filename);
                cout << "Tong tien cua tat ca cac don hang 'Giao hang thanh cong' la: " << tongTien << "000  VND" << endl;
                break;
            }
            case 2: {
                long long tongTien = DoanhThu::tinhTongTienSanPhamNhaCungCap(filePath);
                cout << "Tong tien cua tat ca cac don hang 'Nha cung cap' la: " << tongTien << "000 VND" << endl;
                break;
            }
            case 3: {
                long long tongTien = DoanhThu::tinhTongTienSanPhamDangCo(filePath1);
                cout << "Tong tien cua tat ca cac don hang 'San pham dang co' la: " << tongTien << "000 VND" << endl;
                break;
            }
            case 0:
                cout << "Thoat!" << endl;
                break;
            default:
                cout << "Chon khong hop le!" << endl;
                break;
        }
    } while (chon != 0);
}

#endif // QLDT_H