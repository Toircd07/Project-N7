
#include "SanPham.h" // dinh nghia cac ham cua class SanPham
#include <fstream>  
#include <iostream>
#include <string>
#include <vector>

using namespace std;

SanPham::SanPham(){}

// ham khoi tao doi tuong SanPham voi cac gia tri cu the cho cac thuoc tinh
SanPham::SanPham(string maSP, string tenSP, double giaBan, int soLuong)
    : maSP(maSP), tenSP(tenSP),giaBan(giaBan), soLuong(soLuong){};

string SanPham::getMaSP() const {
    return maSP;
}

string SanPham::getTenSP() const {
    return tenSP;
}

double SanPham::getGiaBan() const {
    return giaBan;
}

int SanPham::getSoLuong() const {
    return soLuong;
}

void SanPham::setSoLuong(int soLuong) {
    this->soLuong = soLuong;
}

/* Dinh nghia ham themSanPham , ham nay cho phep nguoi dung nhap thong tin ve 1 san pham moi
cac thong tin bao gom : ma san pham , ten san pham , han su dung , gia ban , so luong sau do them san pham nay vao 1 danh sach*/
void SanPham::themSanPham(){
    cout << "Nhap ma san pham: ";
    cin >> maSP;
    cin.ignore();
    cout << "Nhap ten san pham: ";
    getline(cin, tenSP);    // doc toan bo dong dau vao va luu vao bien tenSP , su dung getline de dam bao ten sp co the co khoang trang    
    cout << "Nhap gia ban: ";
    cin >> giaBan;
    cout << "Nhap so luong: ";
    cin >> soLuong;  
            cout <<"                   "<< "============================" << endl;   
            cout <<"                   "<< "[ Them san pham thanh cong ]" << endl;
            cout <<"                   "<< "============================" << endl;   // sau khi nhap xong thong tin thi in ra dong nay
     SanPham sp(maSP, tenSP, giaBan, soLuong);  
    listsp.push_back(sp);                       
    
    luuSanPham();  // goi ham luuSanPham de ghi du lieu vao file "sanpham.txt" sau khi them san pham

}


/* Dinh nghia ham xoaSanPham thuoc class SanPham , 
ham nay cho phep nguoi dung nhap ma san pham cua san pham can xoa , tu do xoa san pham*/
void SanPham::xoaSanPham(){
    cout << "Nhap ma san pham can xoa: ";    
    cin >> maSP;                                    
    for (int i = 0; i < listsp.size(); i++){                 // duyet qua tat ca cac san pham trong ds "listsp"
        if (listsp[i].maSP == maSP){                        // kiem tra xem ma san pham hien tao co trung voi ma san pham ma nguoi dung da nhap hay khong
            listsp.erase(listsp.begin() + i);                // neu trung thi xoa san pham tai vi tri i trong danh sach
            cout <<"                   "<< "===========================" << endl;   
            cout <<"                   "<< "[ Xoa san pham thanh cong ]" << endl;   // in ra dong nay sau khi xoa thanh cong
            cout <<"                   "<< "===========================" << endl;    
                                            
             luuSanPham();
            return;                                      // ket thuc ham khong tiep tuc duyet danh sach nua
        }
      }
     
            cout <<"                   "<< "============================" << endl;   
            cout <<"                   "<< "[ Khong tim thay san pham  ]" << endl;
            cout <<"                   "<< "============================" << endl;    // in ra dong nay neu ko nhap ma san pham khong co trong danh sach
           
}

/*Dinh nghia ham suaSanPham thuoc class SanPham ,
cho phep nguoi dung nhap mot ma san pham ma nguoi dung can thay doi thong tin, sau do thay doi thong tin san pham*/
void SanPham::suaSanPham(){
    string maSP;
    cout << "Nhap ma san pham can sua: ";
    cin >> maSP;
    cin.ignore();
    for (int i = 0; i < listsp.size(); i++){   // duyet qua tat ca cac san pham trong ds "listsp"
        if (listsp[i].maSP == maSP){            // kiem tra xem ma san pham hien tai co trung voi ma san pham ma nguoi dung da nhap hay khong
            cout << "Nhap ten san pham: ";
            getline(cin, listsp[i].tenSP);     // neu trung thi cho phep nguoi dung nhap lai ten san pham
            cout << "Nhap gia ban: ";
            cin >> listsp[i].giaBan;             // cho phep nguoi dung nhap lai gia ban
            cout << "Nhap so luong: ";
            cin >> listsp[i].soLuong;             // cho phep nguoi dung nhap lai so luong
            cout <<"                   "<< "============================" << endl;   
            cout <<"                   "<< "[ Sua san pham thanh cong! ]" << endl;
            cout <<"                   "<< "============================" << endl;  // in ra dong nay sau khi sua thanh cong
            luuSanPham();  
            return;                           // ket thuc ham khong tiep tuc duyet danh sach nua
            
        }
    }
            cout <<"                   "<< "============================" << endl;   
            cout <<"                   "<< "[ Khong tim thay san pham  ]" << endl;
            cout <<"                   "<< "============================" << endl;   // in ra dong nay neu ko tim thay ma san pham trong danh sach
}
/*Dinh nghia ham hienThi thuoc class SanPham */
void SanPham::hienThi(const int& i){
    
        cout << "|  " << i+1 ;  
        int dem = 0 ;                            /*hien thi so thu tu cua tung san pham nhap vao danh sach*/
        while(1){                                   
            if(dem<7-to_string(i+1).length()){          
                cout << " ";
                dem++;
            }else{
                break ;}
        }
        cout << "|      " << listsp[i].maSP ;
        for(int  j=0; j<11-listsp[i].maSP.length(); j++){        /*hien thi ma san pham*/
            cout << " ";
        }
        cout << "|   " << listsp[i].tenSP ;
        for(int  j=0; j<33-listsp[i].tenSP.length(); j++){         /*hien thi ten san pham*/
            cout << " ";
        }
        cout << "|      "  << listsp[i].giaBan ;
        for(int  j=0; j<19-to_string(listsp[i].giaBan).length(); j++){  /*hien thi gia ban*/
            cout << " ";  
        }
        cout << "|    "  << listsp[i].soLuong ;
        for(int  j=0; j<10-to_string(listsp[i].soLuong).length(); j++){   /*hien thi so luong*/
            cout << " ";
        }
        cout << "|" << endl;
    }
/*Dinh nghia ham hienThiDanhSachSanPham thuoc class SanPham ,
trong ham nay goi ham hienThi o tren de in ra danh sach san pham*/
void SanPham::hienThiDanhSachSanPham(){
     cout << "|   STT   |   Ma san pham   |            Ten san pham            |    Gia ban(K)    |   So luong   |" << endl;
    for (int i = 0; i < listsp.size(); i++){
        hienThi(i);
    }
}
/*Dinh nghia ham timKiemSanPham thuoc class SanPham ,
ham nay cho phep nhap vao ma san pham can tim kiem , sau do se hien thi thong tin day du cua san pham vua nhap ma ,
ham nay cung goi ham hienThi o tren 1 lan nua de in ra duoc thong tin san pham can tim kiem*/
void SanPham::timKiemSanPham(){
    string maSP;
    cout << "Nhap ma san pham can tim: ";
    cin >> maSP;
    for (int i = 0; i < listsp.size(); i++){

        if (listsp[i].maSP == maSP){
     cout << "|   STT   |   Ma san pham   |            Ten san pham            |    Gia ban(K)    |   So luong   |" << endl;
            hienThi(i);
            return;
        }
    }
            cout <<"                   "<< "============================" << endl;   
            cout <<"                   "<< "[ Khong tim thay san pham  ]" << endl;
            cout <<"                   "<< "============================" << endl;
}
/*Dinh nghia ham luuSanPham thuoc class SanPham ,
ham nay cho ghi du lieu san pham vao file "sanpham.txt"*/
void SanPham::luuSanPham(){
    ofstream file("data/sanpham.txt");   // mo file "sanpham.txt" de ghi du lieu , neu file chua ton tai thi se tao ra file moi , neu file da ton tai no se bi ghi de
    for (int i = 0; i < listsp.size(); i++){  // duyer qua tung phan tu trong ds "listsp"
        file << listsp[i].maSP << ";" ;       // ghi cac thuoc tinh san pham vao file sau do ghi dau ";" de phan biet giua cac thuoc tinh
        file << listsp[i].tenSP << ";" ;
        file << listsp[i].giaBan << ";" ;
        file << listsp[i].soLuong  << endl;
    }
    cout << "                  " << "================================= " << endl;
    cout << "                  " << "[ Luu file san pham thanh cong! ] " << endl;   // in ra dong nay sau khi luu thanh cong vao file
    cout << "                  " << "================================= " << endl;
    file.close();  // dong file sau khi ghi xong
}
/* Dinh nghia ham docSanPham thuoc class SanPham ,
ham nay se doc du lieu co san trong file "sanpham.txt"  */
void SanPham :: docSanPham(){
    ifstream file("data/sanpham.txt");  // mo file "sanpham.txt" de doc du lieu , neu file ko ton tai thi se bao loi
    if (!file.is_open()) {
    cout << "Khong the mo file !" << endl;
    return;
}
    string giaBanStr, soLuongStr; // khai bao 2 bien string de luu gia ban va so luong san pham
    while (file.good()){    /* doc du lieu trong file cho den khi doc het file tach cac truong
    du lieu bang dau ";" vong lap tiep tuc cho den khi khong con dong nao de doc */
        getline(file, maSP, ';');
        getline(file, tenSP, ';');
        getline(file, giaBanStr, ';');
        getline(file, soLuongStr, '\n');
         if (maSP != ""){     // kiem tra xem ma san pham co rong hay khong
            double giaBan = stod(giaBanStr);  // chuyen doi gia ban tu kieu string sang kieu double
            int soLuong = stoi(soLuongStr);   // chuyen doi so luong tu kieu string sang kieu int
            SanPham sp(maSP, tenSP, giaBan, soLuong);
            listsp.push_back(sp);     // them san pham vao danh sach "listsp"
        }
    }
    cout << "                  " << "================================= " << endl;
    cout << "                  " << "[ Doc file san pham thanh cong! ]" << endl;  // in ra dong nay sau khi doc thanh cong
    cout << "                  " << "================================= " << endl;
    file.close();     // dong file sau khi doc xong
}
vector<SanPham>& SanPham::getDsSP() {
    return listsp;
}