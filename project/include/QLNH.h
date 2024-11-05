// QLNH.h
#ifndef QLNH_H
#define QLNH_H

#include "NhapHang.h"
#include "NhaCungCap.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void QLNHMenu() {
    NhapHang nh;
    NhaCungCap ncc;
    int choice;

    ncc.docNCC();
    nh.docNhapHang();
    do {
        cout << "======================== MENU ========================" << endl;
        cout << "1. Them san pham nhap hang" << endl;
        cout << "2. Xoa san pham nhap hang" << endl;
        cout << "3. Tim kiem san pham nhap hang" << endl;
        cout << "4. Hien thi danh sach san pham nhap hang" << endl;
        cout << "5.Thay doi so luong nhap" << endl;
        cout << "6. Luu danh sach san pham nhap hang" << endl;
        cout << "0. Quay lai" << endl;
        cout << "=====================================================" << endl;
        cout << "Nhap lua chon: ";
        cin >> choice;
        switch (choice) {
        case 1:
            nh.themSPNhap(ncc);
            break;
        case 2:{
            string maSP;
            int soLuongXoa;
            cout << "Nhap ma san pham can xoa: ";
            cin >> maSP;
            nh.xoaNhapHang(maSP);
            break;
        }
        case 3:
            nh.timKiemSPNhap();
            break;
        case 4:
            nh.hienThiDanhSachSPNhap();
            break;
        case 5: {
            string maSP;
            int soLuongMoi;
            cout << "Nhap ma san pham can thay doi: ";
            cin >> maSP;
            cout << "Nhap so luong moi: ";
            cin >> soLuongMoi;
            nh.thayDoiSoLuongNhap(maSP, soLuongMoi, ncc);
            break;
        }
        case 6: 
            nh.luuNhapHang();
            break;
        case 0:
            cout << "Quay lai menu chinh" << endl;
            break;
        default:
            cout << "Lua chon khong hop le. Vui long chon lai!" << endl;
            break;
        }
    } while (choice != 0);
}

#endif // QLNH_H