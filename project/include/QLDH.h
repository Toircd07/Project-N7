#ifndef QLDH_H
#define QLDH_H

#include "DonHang.h"
#include "KhachHang.h"
#include "SanPham.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;
 
void QLDHMenu() {
    KhachHang khachHang;
    khachHang.docDSCus();

    SanPham sanPham;
    sanPham.docSanPham();

    DonHang dh;
    int choice;
    dh.docDonHang();
    do {
        cout << "======================== MENU ========================" << endl;
        cout << "1. Tao don hang" << endl;
        cout << "2. Sua trang thai don hang" << endl;
        cout << "3. Sua don hang" << endl;
        cout << "4. Hien thi danh sach don hang" << endl;
        cout << "5. Xoa don hang" << endl;
        cout << "6. Tim kiem don hang" << endl;
        cout << "7. Luu don hang" << endl;
        cout << "0. Thoat" << endl;
        cout << "=====================================================" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch (choice) {
        case 1:
            dh.taoDonHang(khachHang, sanPham);
            break;
        case 2: {
            string maDH, trangThaiMoi;
            cout << "Nhap ma don hang can cap nhat trang thai: ";
            cin >> maDH;
            cin.ignore();
            cout << "Nhap trang thai moi (Dang xu ly, Dang giao hang, Giao hang thanh cong): ";
            getline(cin, trangThaiMoi);
            dh.suaTrangThaiDonHang(maDH, trangThaiMoi);
            break;
        }
        case 3:
            dh.suaDonHang();
            break;
        case 4:
            dh.hienThiDanhSachDonHang();
            break;
        case 5:
            dh.xoaDonHang();
            break;
        case 6:
            dh.timKiemDonHang();
            break;
        case 7:
            dh.luuDonHang();
            break;
        case 0:
            cout << "Thoat chuong trinh." << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai." << endl;
            break;
        }
    } while (choice != 0);
}

#endif // QLDH_H