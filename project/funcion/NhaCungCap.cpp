
#include "NhaCungCap.h"
#include <fstream>  
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

NhaCungCap::NhaCungCap(){}
NhaCungCap::NhaCungCap(string maNCC ,string tenNCC,string maSanPham ,string tenSpNhap, int soLuong, double giaSanPham)
    :maNCC(maNCC), tenNCC(tenNCC), maSanPham(maSanPham), tenSpNhap(tenSpNhap), soLuong(soLuong), giaSanPham(giaSanPham){}

string NhaCungCap::getMaNCC() const{
    return maNCC;
}

string NhaCungCap::getTenNCC() const{
    return tenNCC;
}

string NhaCungCap::getMaSanPham() const{
    return maSanPham;
}

string NhaCungCap::getTenSpNhap() const{
    return tenSpNhap;
}

int NhaCungCap::getSoLuong() const{
    return soLuong;
}

double NhaCungCap::getGiaSanPham() const{
    return giaSanPham;
}

void NhaCungCap::setSoLuong(int soLuong){
    this->soLuong = soLuong;
}

vector<NhaCungCap>& NhaCungCap::getDsNCC(){
    return listNCC;
}

vector<pair<string, int>>& NhaCungCap::getSanPhamSoLuong(){
    return sanPhamSoLuong;
}

void NhaCungCap::themNCC(){
    int soLuongThem;
    cout << "Nhap so luong nha cung cap muon them: ";
    cin >> soLuongThem;
    cin.ignore();

    vector<NhaCungCap> tempNCCList;

    for (int i = 0; i < soLuongThem; i++) {
        cout << "Nhap ma nha cung cap: ";
        // neu nhap vao xau rong , bat buoc nhap lai
        do{
            getline(cin, maNCC);
            if(maNCC.empty()){
                cout << "Ma nha cung cap khong duoc de trong . Vui long nhap lai: " ;
            }
        } while(maNCC.empty());
        cout << "Nhap ten nha cung cap: ";
        do{
            getline(cin, tenNCC);
            if(tenNCC.empty()){
                cout << "Ten nha cung cap khong duoc de trong . Vui long nhap lai: " ;
            }
        } while(tenNCC.empty());

        // Thêm sản phẩm cho nhà cung cấp
        cout << "Nhap ma san pham: ";
        do{
            getline(cin, maSanPham);
            if(maSanPham.empty()){
                cout << "Ma san pham khong duoc de trong . Vui long nhap lai: " ;
            }
        } while(maSanPham.empty());
        cout << "Nhap ten san pham nhap: ";
        do{
            getline(cin, tenSpNhap);
            if(tenSpNhap.empty()){
                cout << "Ten san pham nhap khong duoc de trong . Vui long nhap lai: " ;}
        } while(tenSpNhap.empty());

        cout << "Nhap so luong: ";
        do{
            cin >> soLuong;
            if(soLuong<= 0){
                cout << "So luong phai lon hon 0 . Vui long nhap lai: " ;
            }
        } while(soLuong <= 0);
        cout << "Nhap gia san pham: ";
        do{
            cin >> giaSanPham;
            if(giaSanPham == 0){
                cout << "Gia san pham khong duoc de trong . Vui long nhap lai: " ;
            }
        } while(giaSanPham == 0);
        cin.ignore();
        NhaCungCap ncc(maNCC, tenNCC, maSanPham, tenSpNhap, soLuong, giaSanPham);
        tempNCCList.push_back(ncc);

        // Thêm dòng phân cách sau mỗi lần nhập xong một sản phẩm
        if (soLuongThem > 1 && i < soLuongThem - 1) {
            cout << "-----------------------------------------" << endl;
        }
    }

    if (soLuongThem == 1) {
        listNCC.push_back(tempNCCList[0]);
        luuNCC();
        cout <<"                        "<<"================================= " << endl;
        cout <<"                        "<<"[ Them nha cung cap thanh cong! ] " << endl;
        cout <<"                        "<<"================================= " << endl;
    } else {
        char choice;
        cout << "Ban co muon luu danh sach nha cung cap khong? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            for (const auto& ncc : tempNCCList) {
                listNCC.push_back(ncc);
            }
            luuNCC();
            cout <<"                        "<<"================================= " << endl;
            cout <<"                        "<<"[ Them nha cung cap thanh cong! ] " << endl;
            cout <<"                        "<<"================================= " << endl;
        } else {
            cout <<"                        "<<"================================= " << endl;
            cout <<"                        "<<"[ Them nha cung cap that bai! ] " << endl;
            cout <<"                        "<<"================================= " << endl;
        }
    }
}

void NhaCungCap::suaNCC(){
    int soLuongSua;
    cout << "Nhap so luong nha cung cap muon sua: ";
    cin >> soLuongSua;
    cin.ignore();

    vector<NhaCungCap> tempNCCList;
    bool suaThanhCong = false;

    for (int j = 0; j < soLuongSua; j++) {
        cout << "Nhap ma nha cung cap can sua: ";
        cin >> maNCC;
        cin.ignore();
        for (int i = 0; i < listNCC.size(); i++){
            if (listNCC[i].maNCC == maNCC){
                cout << "Nhap ten nha cung cap: ";
                // neu nhap vao xau rong , bat buoc nhap lai
                do{
                    getline(cin, tenNCC);
                    if(tenNCC.empty()){
                        cout << "Ten nha cung cap khong duoc de trong . Vui long nhap lai: " ;
                    }
                } while(tenNCC.empty());

                cout << "Nhap ma san pham: ";
                do{
                    getline(cin, maSanPham);
                    if(maSanPham.empty()){
                        cout << "Ma san pham khong duoc de trong . Vui long nhap lai: " ;
                    }
                } while(maSanPham.empty());

                cout << "Nhap ten san pham nhap: ";
                do{
                    getline(cin, tenSpNhap);
                    if(tenSpNhap.empty()){
                        cout << "Ten san pham nhap khong duoc de trong . Vui long nhap lai: " ;
                    }
                } while(tenSpNhap.empty());

                cout << "Nhap so luong: ";
                do{
                    cin >> soLuong;
                    if(soLuong<= 0){
                        cout << "So luong phai lon hon 0 . Vui long nhap lai: " ;
                    }
                } while(soLuong <= 0);

                cout << "Nhap gia san pham: ";
                do{
                    cin >> giaSanPham;
                    if(giaSanPham == 0){
                        cout << "Gia san pham khong duoc de trong . Vui long nhap lai: " ;
                    }
                } while(giaSanPham == 0);
                cin.ignore();

                NhaCungCap ncc(maNCC, tenNCC, maSanPham, tenSpNhap, soLuong, giaSanPham);
                tempNCCList.push_back(ncc);
                suaThanhCong = true;
                break;
            }
        }
        if (!suaThanhCong) {
            cout <<"                        "<<"================================ " << endl;
            cout <<"                        "<<"[ Khong tim thay nha cung cap! ] " << endl;
            cout <<"                        "<<"================================ " << endl;
        }

        // Thêm dòng phân cách sau mỗi lần sửa xong một sản phẩm
        if (soLuongSua > 1 && j < soLuongSua - 1) {
            cout << "-----------------------------------------" << endl;
        }
    }

    if (soLuongSua == 1) {
        listNCC.push_back(tempNCCList[0]);
        luuNCC();
        cout <<"                        "<<"================================ " << endl;
        cout <<"                        "<<"[ Sua nha cung cap thanh cong! ] " << endl;
        cout <<"                        "<<"================================ " << endl;
    } else if (suaThanhCong) {
        char choice;
        cout << "Ban co muon luu danh sach nha cung cap khong? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            for (const auto& ncc : tempNCCList) {
                listNCC.push_back(ncc);
            }
            luuNCC();
            cout <<"                        "<<"================================ " << endl;
            cout <<"                        "<<"[ Sua nha cung cap thanh cong! ] " << endl;
            cout <<"                        "<<"================================ " << endl;
        } else {
            cout <<"                        "<<"================================ " << endl;
            cout <<"                        "<<"    [ Huy thao tac sua! ] " << endl;
            cout <<"                        "<<"================================ " << endl;
        }
    }
}

void NhaCungCap::xoaNCC(){
    int soLuongXoa;
    cout << "Nhap so luong san pham muon xoa: ";
    cin >> soLuongXoa;
    cin.ignore();

    vector<int> indicesToDelete;
    bool xoaThanhCong = false;

    for (int j = 0; j < soLuongXoa; j++) {
        string maSanPham;
        cout << "Nhap ma san pham can xoa: ";
        cin >> maSanPham;
        bool found = false;
        for (int i = 0; i < listNCC.size(); i++){
            if (listNCC[i].maSanPham == maSanPham){
                indicesToDelete.push_back(i);
                found = true;
                xoaThanhCong = true;
                break;
            }
        }
        if (!found) {
            cout <<"                        "<<"================================ " << endl;
            cout <<"                        "<<"[ Khong tim thay san pham! ] " << endl;
            cout <<"                        "<<"================================ " << endl;
        } else {
            cout <<"                        "<<"================================ " << endl;
            cout <<"                        "<<  "[ Xoa san pham thanh cong! ] " << endl;
            cout <<"                        "<<"================================ " << endl;
        }

        // Thêm dòng phân cách sau mỗi lần xóa xong một sản phẩm
        if (soLuongXoa > 1 && j < soLuongXoa - 1) {
            cout << "-----------------------------------------" << endl;
        }
    }

    if (soLuongXoa == 1) {
        for (int index : indicesToDelete) {
            listNCC.erase(listNCC.begin() + index);
        }
        luuNCC();
    } else if (xoaThanhCong) {
        char choice;
        cout << "Ban co muon luu danh sach nha cung cap khong? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            for (int index : indicesToDelete) {
                listNCC.erase(listNCC.begin() + index);
            }
            luuNCC();
            cout <<"                        "<<"================================ " << endl;
            cout <<"                        "<<  "[ Xoa san pham thanh cong! ] " << endl;
            cout <<"                        "<<"================================ " << endl;
        } else {
            cout <<"                        "<<"================================ " << endl;
            cout <<"                        "<<      "[ Huy thao tac xoa! ] " << endl;
            cout <<"                        "<<"================================ " << endl;
        }
    }
}

void NhaCungCap :: hienThi(const int &i){
    cout << "|  " << i+1 ;
        int dem = 0 ;
        while(1){
            if(dem<7-to_string(i+1).length()){
                cout << " ";
                dem++;
            }else
                break ;
        }
        cout << "|      " << listNCC[i].maNCC ;
        for(int  j=0; j<15-listNCC[i].maNCC.length(); j++){
            cout << " ";
        }
        cout << "|   " << listNCC[i].tenNCC ;
        for(int  j=0; j<33-listNCC[i].tenNCC.length(); j++){
            cout << " ";
        }
        cout << "|   " << listNCC[i].maSanPham ;
        for(int  j=0; j<22-listNCC[i].maSanPham.length(); j++){
            cout << " ";
        }
        cout << "|   " << listNCC[i].tenSpNhap ;
        for(int  j=0; j<27-listNCC[i].tenSpNhap.length(); j++){
            cout << " ";
        }
        cout << "|    " << listNCC[i].soLuong ;
        for(int  j=0; j<12-to_string(listNCC[i].soLuong).length(); j++){
            cout << " ";
        }
        cout << "|     " << listNCC[i].giaSanPham ;
        for(int  j=0; j<20-to_string(listNCC[i].giaSanPham).length(); j++){
            cout << " ";
        }
        cout << "|" << endl;

}
void NhaCungCap::hienThidanhsachNCC(){
    cout <<"                                                        "<< "========================== " << endl;
    cout <<"                                                        "<< "[ Danh sach nha cung cap ] " << endl;
    cout <<"                                                        "<< "========================== " << endl;
    cout <<"                                                        "<< "                           " << endl;
    cout <<"                                                        "<< "                           " << endl;

    cout << "|   STT   |   Ma nha cung cap   |          Ten nha cung cap          |       Ma san pham       |         Ten san pham         |     So luong   |    Gia san pham  |" << endl;
    for (int i = 0; i < listNCC.size(); i++){
        hienThi(i);
    }
}
void NhaCungCap::timKiemNCC(){
    string maNCC;
    cout << "Nhap ma nha cung cap can tim: ";
    cin >> maNCC;
    for (int i = 0; i < listNCC.size(); i++){
        if (listNCC[i].maNCC == maNCC){
    cout << "|   STT   |   Ma nha cung cap   |          Ten nha cung cap          |       Ma san pham       |         Ten san pham         |     So luong   |    Gia san pham  |" << endl;
            hienThi(i);
            return;
        }
    }
    cout <<"                            "<<"================================ " << endl;
    cout <<"                            "<<"[ Khong tim thay nha cung cap! ] " << endl;
    cout <<"                            "<<"================================ " << endl;
}

void NhaCungCap::luuNCC(){
    ofstream file("data/nhacungcap.txt");
    for (int i = 0; i < listNCC.size(); i++){
        file << listNCC[i].maNCC << ";" ;
        file << listNCC[i].tenNCC << ";" ;
        file << listNCC[i].maSanPham << ";" ;
        file << listNCC[i].tenSpNhap << ";" ;
        file << listNCC[i].soLuong << ";" ;
        file << listNCC[i].giaSanPham << '\n' ;
    }
    cout << "                       " <<"========================================== " << endl;
    cout << "                       " <<"[ Luu danh sach nha cung cap thanh cong! ] " << endl;
    cout << "                       " <<"========================================== " << endl;
    file.close();
}

void NhaCungCap::docNCC() {
    ifstream file("data/nhacungcap.txt");
    if (!file.is_open()) {
        cout << "                       "<<"========================================= " << endl;
        cout << "                       "<<"[ Khong the mo danh sach nha cung cap ! ] " << endl;
        cout << "                       "<<"========================================= " << endl;  
        return;
    }
    listNCC.clear();
    string giaSanPhamStr;
    string soLuongStr;
    while (file.good()) {
        getline(file, maNCC, ';');
        getline(file, tenNCC, ';');
        getline(file, maSanPham, ';');
        getline(file, tenSpNhap, ';');
        getline(file, soLuongStr, ';');
        getline(file, giaSanPhamStr, '\n');

        if (!maNCC.empty() && !giaSanPhamStr.empty()) {
            try {
                double giaSanPham = stod(giaSanPhamStr);
                int soLuong = stoi(soLuongStr);
                NhaCungCap ncc(maNCC, tenNCC, maSanPham, tenSpNhap, soLuong, giaSanPham);
                listNCC.push_back(ncc);
            } catch (const invalid_argument& e) {
                cout << "Loi: Khong the chuyen doi gia san pham '" << giaSanPhamStr << "' thanh so thuc." << endl;
            }
        }
    }
    cout << "                       "<<"========================================== " << endl;
    cout << "                       "<<"[ Doc danh sach nha cung cap thanh cong! ] " << endl;
    cout << "                       "<<"========================================== " << endl;   
    file.close();
}

void NhaCungCap::luuDuLieuRaFile(const string& filePath) {
    ofstream file(filePath);
    if (!file.is_open()) {
        cerr << "Khong the mo file: " << filePath << endl;
        return;
    }

    for (const auto& ncc : listNCC) {
        file << ncc.getMaNCC() << ";"
             << ncc.getTenNCC() << ";"
             << ncc.getMaSanPham() << ";"
             << ncc.getTenSpNhap() << ";"
             << ncc.getSoLuong() << ";"
             << ncc.getGiaSanPham() << endl;
    }

    file.close();
}

void NhaCungCap::docDuLieuTuFile(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Khong the mo file: " << filePath << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string maNCC, tenNCC, maSP, tenSP, soLuongStr, giaStr;
        int soLuong;
        double gia;

        getline(ss, maNCC, ';');
        getline(ss, tenNCC, ';');
        getline(ss, maSP, ';');
        getline(ss, tenSP, ';');
        getline(ss, soLuongStr, ';');
        getline(ss, giaStr, ';');

        try {
            soLuong = stoi(soLuongStr);
            gia = stod(giaStr);
        } catch (const invalid_argument& e) {
            cerr << "Loi: Khong the chuyen doi gia tri '" << line << "' thanh so nguyen hoac so thuc." << endl;
            continue;
        }

        listNCC.emplace_back(maNCC, tenNCC, maSP, tenSP, soLuong, gia);
    }

    file.close();
}
