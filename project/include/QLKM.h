#include"KhuyenMai.h"
#include<iostream>

using namespace std;

void QLKMmenu(){
    KhuyenMai km;
    int chon;
    km.docFile();
    do{
        cout << "======================== MENU ========================" << endl;
        cout << "1. Them khuyen mai" << endl;
        cout << "2. Xoa khuyen mai" << endl;
        cout << "3. Sua khuyen mai" << endl;
        cout << "4. Xem danh sach khuyen mai" << endl;
        cout << "5. Tim kiem khuyen mai" << endl;
        cout << "0. Thoat" << endl;
        cout << "=====================================================" << endl;
        cout << "Nhap lua chon: ";
        cin >> chon;
        switch(chon){
            case 1:
                km.themKM();
                break;
            case 2:
                km.xoaKM();
                break;
            case 3:
                km.suaKM();
                break;
            case 4:
                km.xemDSKM();
                break;
            case 5:
                km.timKiemKM();
                break;
            case 0:
                cout << "Thoat!" << endl;
                break;
            default:
                cout << "Chon khong hop le!" << endl;
                break;
        }
    } while(chon != 0);
}