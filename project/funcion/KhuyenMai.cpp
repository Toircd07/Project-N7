#include"KhuyenMai.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

KhuyenMai :: KhuyenMai(){}
KhuyenMai :: KhuyenMai(string maKM, string tenKM, string ngayBD, string ngayKT, string phanTramKM,int soLuong) :
    maKM(maKM), tenKM(tenKM), ngayBD(ngayBD), ngayKT(ngayKT), phanTramKM(phanTramKM) ,soLuong(soLuong){}

void KhuyenMai :: themKM(){
    cout << "Nhap ma khuyen mai: ";
    cin >> maKM;
    cin.ignore();
    cout << "Nhap ten khuyen mai: ";
    getline(cin, tenKM);
    cout << "Nhap ngay bat dau: ";
    cin >> ngayBD;
    cout << "Nhap ngay ket thuc: ";
    cin >> ngayKT;
    cout << "Nhap phan tram khuyen mai: ";
    cin >> phanTramKM;
    cout << "Nhap so luong: ";
    cin >> soLuong;

    KhuyenMai km(maKM, tenKM, ngayBD, ngayKT, phanTramKM, soLuong);
    dsKM.push_back(km);
    cout << "Them thanh cong!" << endl;
    ghiFile();
}

void KhuyenMai :: xoaKM(){
    string ma;
    cout << "Nhap ma khuyen mai can xoa: ";
    cin >> ma;
    for(int i = 0; i < dsKM.size(); i++){
        if(dsKM[i].maKM == ma){
            dsKM.erase(dsKM.begin() + i);
            cout << "Xoa thanh cong!" << endl;
            ghiFile();
            return;
        }
    }
    cout << "Khong tim thay ma khuyen mai!" << endl;
}

void KhuyenMai :: suaKM(){
    string ma;
    cout << "Nhap ma khuyen mai can sua: ";
    cin >> ma;
    for(int i = 0; i < dsKM.size(); i++){
        if(dsKM[i].maKM == ma){
            cout << "Nhap ten khuyen mai: ";
            cin.ignore();
            getline(cin, dsKM[i].tenKM);
            cout << "Nhap ngay bat dau: ";
            cin >> dsKM[i].ngayBD;
            cout << "Nhap ngay ket thuc: ";
            cin >> dsKM[i].ngayKT;
            cout << "Nhap phan tram khuyen mai: ";
            cin >> dsKM[i].phanTramKM;
            cout << "Nhap so luong: ";
            cin >> dsKM[i].soLuong;
            cout << "Sua thanh cong!" << endl;
            ghiFile();
            return;
        }
    }
    cout << "Khong tim thay ma khuyen mai!" << endl;
}
void KhuyenMai :: xemDSKM(){
    for(int i = 0; i < dsKM.size(); i++){
        cout << "--------------------------------" << endl;
        cout << "Ma khuyen mai: " << dsKM[i].maKM << endl;
        cout << "Ten khuyen mai: " << dsKM[i].tenKM << endl;
        cout << "Ngay bat dau: " << dsKM[i].ngayBD << endl;
        cout << "Ngay ket thuc: " << dsKM[i].ngayKT << endl;
        cout << "Phan tram khuyen mai: " << dsKM[i].phanTramKM << endl;
        cout << "So luong: " << dsKM[i].soLuong << endl;
        cout << "--------------------------------" << endl;
    }

}

void KhuyenMai :: timKiemKM(){
    string ma;
    cout << "Nhap ma khuyen mai can tim: ";
    cin >> ma;
    for(int i = 0; i < dsKM.size(); i++){
        if(dsKM[i].maKM == ma){
             cout << "--------------------------------" << endl;
            cout << "Ma khuyen mai: " << dsKM[i].maKM << endl;
            cout << "Ten khuyen mai: " << dsKM[i].tenKM << endl;
            cout << "Ngay bat dau: " << dsKM[i].ngayBD << endl;
            cout << "Ngay ket thuc: " << dsKM[i].ngayKT << endl;
            cout << "Phan tram khuyen mai: " << dsKM[i].phanTramKM << endl;
            cout << "So luong: " << dsKM[i].soLuong << endl;
             cout << "--------------------------------" << endl;
            ghiFile();
            return;
        }
    }
    cout << "Khong tim thay ma khuyen mai!" << endl;
}
void KhuyenMai :: docFile(){
    ifstream file("data/KhuyenMai.txt");
    if(!file.is_open()){
        cout << "Khong the mo file!" << endl;
        return;
    }
    dsKM.clear();
    string ma, ten, ngayBD, ngayKT, phanTramKM ;
    string soLuongSTR;
    while(file.good()){
        getline(file, ma, ';');
        getline(file, ten, ';');
        getline(file, ngayBD, ';');
        getline(file, ngayKT, ';');
        getline(file, phanTramKM, ';');
        getline(file, soLuongSTR, '\n');
        if(ma != ""){
            int soLuong= stoi(soLuongSTR);
            KhuyenMai km(ma, ten, ngayBD, ngayKT, phanTramKM, soLuong);
            dsKM.push_back(km);
        }
    }
    cout << "Doc file thanh cong!" << endl;
    file.close();
}
void KhuyenMai :: ghiFile(){
    ofstream file("data/KhuyenMai.txt");
    for(int i = 0; i < dsKM.size(); i++){
        file << dsKM[i].maKM << ";";
        file << dsKM[i].tenKM << ";";
        file << dsKM[i].ngayBD << ";";
        file << dsKM[i].ngayKT << ";";
        file << dsKM[i].phanTramKM << ";";
        file << dsKM[i].soLuong << endl;
    }
    cout << "Ghi file thanh cong!" << endl;
    file.close();
}