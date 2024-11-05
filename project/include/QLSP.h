#ifndef QLSP_H         // kiem tra xem file QLSP.h da duoc dinh nghia chua
#define QLSP_H

#include "SanPham.h"    // dinh nghia cac ham cua class SanPham
#include <iostream>
#include <string>

using namespace std;

void QLSPmenu(){
    SanPham sp;     // tao ra 1 doi tuong sp thuoc class SanPham
    int luaChon;    // bien lua chon de lua chon chuc nang
        sp.docSanPham();  // doc du lieu san pham tu file "sanpham.txt"
    do{
        cout<<"======================== MENU ========================" << endl;
        cout<<"1. Them san pham"<<endl;                   // in ra cac chuc nang cua chuong trinh
        cout<<"2. Xoa san pham"<<endl;
        cout<<"3. Sua san pham"<<endl;
        cout<<"4. Hien thi danh sach san pham"<<endl;
        cout<<"5. Tim kiem san pham"<<endl;
        cout<<"6. Luu san pham"<<endl;
        cout<<"0. Thoat"<<endl;
        cout<<"======================================================" << endl;
        cout<<"Nhap lua chon: ";
        cin >> luaChon;     // nhap lua chon
        switch(luaChon){        // xu ly lua chon
            case 1:
                sp.themSanPham();   // goi ham themSanPham de them san pham
                break;
            case 2:
                sp.xoaSanPham();    // goi ham xoaSanPham de xoa san pham
                break;
            case 3:
                sp.suaSanPham();    // goi ham suaSanPham de sua san pham
                break;
            case 4:
                sp.hienThiDanhSachSanPham();  // goi ham hienThiDanhSachSanPham de hien thi danh sach san pham
                break;
            case 5:
                sp.timKiemSanPham();    // goi ham timKiemSanPham de tim kiem san pham
                break;
            case 6:
                sp.luuSanPham();        // goi ham luuSanPham de luu san pham vao file
                break;
            case 0:
                cout<<"Ket thuc chuong trinh"<<endl;   // thoat chuong trinh
                break;
            default:
                cout<<"Lua chon khong hop le"<<endl;   //nhap so khac ngoai 0-6 thi in ra dong nay
                break;
        }
    }while(luaChon != 0);        // lap lai neu lua chon khac 0
}

#endif // QLSP_H   //   ket thuc file QLSP.h