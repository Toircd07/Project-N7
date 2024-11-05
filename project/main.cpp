#include "QLSP.h"
#include "QLNV.h"
#include "QLKH.h"
#include "QLNCC.h"
#include "QLDH.h"
#include "QLKM.h"
#include "QLDT.h"
#include "QLNH.h"
#include <iostream>

using namespace std;



int main(){
   
    int luaChon;
    do{
        cout <<"                            " << "--------------------------------" <<endl;
        cout <<"                            " << "| Xin chao hay chon chuc nang! |" <<endl;
        cout <<"                            " << "--------------------------------" <<endl;
        cout <<"                                  " <<"--------Menu----------- "     <<endl;
        cout <<"                                  " <<"1. Quan ly san pham"      <<endl;
        cout <<"                                  " <<"2. Quan ly nhan vien"     <<endl;
        cout <<"                                  " <<"3. Quan ly khach hang"    <<endl;
        cout <<"                                  " <<"4. Quan ly nha cung cap"  <<endl;
        cout <<"                                  " <<"5. Quan ly don hang"      <<endl;
        cout <<"                                  " <<"6. Quan ly khuyen mai"    <<endl;
        cout <<"                                  " <<"7. Quan ly nhap hang"     <<endl;
        cout <<"                                  " <<"8. Thong ke doanh thu"    <<endl;
        cout <<"                                  " <<"0. Thoat"                 <<endl;
        cout <<"                                  " <<"----------------------- " <<endl;
        cout <<"                                  " <<"Nhap lua chon: ";
        cin >> luaChon;
        switch(luaChon){
            case 1:
                QLSPmenu();
                break;
            case 2:
                QLNhanVienmenu();
                break;
            case 3:
                QLKHmenu();
                break;
            case 4:
                QLNCCMenu();
                break;
            case 5:
                QLDHMenu();
                break;
            case 6:
                QLKMmenu();
                break;
            case 7:
                QLNHMenu();
                break;
            case 8:
                QLDTmenu();
                break;
            case 0:
                cout <<"                    " << "-------------------------" << endl;
                cout <<"                    " << "| Ket thuc chuong trinh |" << endl;
                cout <<"                    " << "-------------------------" << endl;
                break;
            default:
                cout <<"                    " << "-------------------------" << endl;
                cout <<"                    " << "| Lua chon khong hop le |" << endl;
                cout <<"                    " << "-------------------------" << endl;
                break;

        }
    }while(luaChon != 0);
}