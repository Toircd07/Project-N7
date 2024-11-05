#include "NhanVien.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<NhanVien> listNV;

NhanVien::NhanVien() {};
NhanVien::NhanVien(string maNV, string hoTen, string caLamViec, string soDT, string email)
    : maNV(maNV), hoTen(hoTen), caLamViec(caLamViec), soDT(soDT), email(email) {};

void NhanVien::ThemNhanVien() {
    int soLuong;
    cout << "Nhap so luong nhan vien can them: ";
    cin >> soLuong;
    cin.ignore();

    vector<NhanVien> danhSachThem;

    for (int j = 0; j < soLuong; j++) {
        string maNV, hoTen, caLamViec, soDT, email;

        cout << "Nhap ma nhan vien: ";
        do {
            getline(cin, maNV);
            if (maNV.empty()) {
                cout << "Ma nhan vien khong duoc de trong. Vui long nhap lai: ";
            }
        } while (maNV.empty());

        cout << "Nhap ho ten: ";
        do {
            getline(cin, hoTen);
            if (hoTen.empty()) {
                cout << "Ho ten khong duoc de trong. Vui long nhap lai: ";
            }
        } while (hoTen.empty());

        cout << "Nhap ca lam viec: ";
        do {
            getline(cin, caLamViec);
            if (caLamViec.empty()) {
                cout << "Ca lam viec khong duoc de trong. Vui long nhap lai: ";
            }
        } while (caLamViec.empty());

        cout << "Nhap so dien thoai: ";
        do {
            getline(cin, soDT);
            if (soDT.empty()) {
                cout << "So dien thoai khong duoc de trong. Vui long nhap lai: ";
            }
        } while (soDT.empty());

        cout << "Nhap email: ";
        do {
            getline(cin, email);
            if (email.empty()) {
                cout << "Email khong duoc de trong. Vui long nhap lai: ";
            }
        } while (email.empty());

        NhanVien nv(maNV, hoTen, caLamViec, soDT, email);
        danhSachThem.push_back(nv);
    }

    char confirm;
    cout << "Ban co muon them nhan vien nay khong? (y/n): ";
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y') {
        for (const NhanVien& nv : danhSachThem) {
            listNV.push_back(nv);
        }
        LuuDSNhanVien();
        cout << "                        " << "================================= " << endl;
        cout << "                          " << "[ Them nhan vien thanh cong ]" << endl;
        cout << "                        " << "================================= " << endl;
    } else {
        cout << "                        " << "================================= " << endl;
        cout << "                          " << "[ Khong them nhan vien ]" << endl;
        cout << "                        " << "================================= " << endl;
    }
}

void NhanVien::XoaNhanVien() {
    int soLuong;
    cout << "Nhap so luong nhan vien can xoa: ";
    cin >> soLuong;
    cin.ignore();

    vector<string> danhSachXoa;

    for (int j = 0; j < soLuong; j++) {
        string maNV;
        cout << "Nhap ma nhan vien can xoa: ";
        cin >> maNV;
        danhSachXoa.push_back(maNV);
    }

    char confirm;
    cout << "Ban co chac chan muon xoa cac nhan vien nay khong? (y/n): ";
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y') {
        for (const string& maNV : danhSachXoa) {
            bool found = false;
            for (int i = 0; i < listNV.size(); i++) {
                if (listNV[i].maNV == maNV) {
                    listNV.erase(listNV.begin() + i);
                    cout << "                        " << "=========================================== " << endl;
                    cout << "                        " << "[ Xoa nhan vien " << maNV << " thanh cong ]" << endl;
                    cout << "                        " << "===========================================" << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "                        " << "=========================================== " << endl;
                cout << "                        " << "[ Khong tim thay nhan vien " << maNV << " ]" << endl;
                cout << "                        " << "=========================================== " << endl;
            }
        }
        LuuDSNhanVien();
    } else {
        cout << "                        " << "================================= " << endl;
        cout << "                             " << "[ Khong xoa nhan vien ]" << endl;
        cout << "                        " << "================================= " << endl;
    }
}

void NhanVien::SuaNhanVien() {
    int soLuong;
    cout << "Nhap so luong nhan vien can sua: ";
    cin >> soLuong;
    cin.ignore();

    vector<string> danhSachSua;

    for (int j = 0; j < soLuong; j++) {
        string maNV;
        cout << "Nhap ma nhan vien can sua: ";
        cin >> maNV;
        cin.ignore();
        danhSachSua.push_back(maNV);
    }

    bool hasChanges = false;

    for (const string& maNV : danhSachSua) {
        bool found = false;
        for (int i = 0; i < listNV.size(); i++) {
            if (listNV[i].maNV == maNV) {
                string hoTen, caLamViec, soDT, email;

                cout << "Nhap ho ten: ";
                do {
                    getline(cin, hoTen);
                    if (hoTen.empty()) {
                        cout << "Ho ten khong duoc de trong. Vui long nhap lai: ";
                    }
                } while (hoTen.empty());

                cout << "Nhap ca lam viec: ";
                do {
                    getline(cin, caLamViec);
                    if (caLamViec.empty()) {
                        cout << "Ca lam viec khong duoc de trong. Vui long nhap lai: ";
                    }
                } while (caLamViec.empty());

                cout << "Nhap so dien thoai: ";
                do {
                    getline(cin, soDT);
                    if (soDT.empty()) {
                        cout << "So dien thoai khong duoc de trong. Vui long nhap lai: ";
                    }
                } while (soDT.empty());

                cout << "Nhap email: ";
                do {
                    getline(cin, email);
                    if (email.empty()) {
                        cout << "Email khong duoc de trong. Vui long nhap lai: ";
                    }
                } while (email.empty());

                listNV[i] = NhanVien(maNV, hoTen, caLamViec, soDT, email);
                hasChanges = true;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "                        " << "================================= " << endl;
            cout << "                        " << "[ Khong tim thay nhan vien " << maNV << " ]" << endl;
            cout << "                        " << "================================= " << endl;
        }
    }

    if (hasChanges) {
        char confirm;
        cout << "Ban co muon luu lai cac thay doi nay khong? (y/n): ";
        cin >> confirm;
        if (confirm == 'y' || confirm == 'Y') {
            LuuDSNhanVien();
            cout << "                        " << "========================================== " << endl;
            cout << "                        " <<   "[ Sua thong tin nhan vien thanh cong ]" << endl;
            cout << "                        " << "========================================== " << endl;
        } else {
            cout << "                        " << "================================ " << endl;
            cout << "                        " <<      "[ Khong luu thay doi ]" << endl;
            cout << "                        " << "================================ " << endl;
        }
    } else {
        cout << "                        " << "================================ " << endl;
        cout << "                        " << "[ Khong co thay doi nao de luu ]" << endl;
        cout << "                        " << "================================= " << endl;
    }
}

void NhanVien::TimKiemNhanVien() {
    string maNV;
    cout << "Nhap ma nhan vien can tim: ";
    cin >> maNV;
    for (int i = 0; i < listNV.size(); i++) {
        if (listNV[i].maNV == maNV) {
            cout << "|  STT  |      ID      |        Ho va ten      |   Ca lam viec  |   So dien thoai   |               Email              |" << endl;
            HienThi(i);
            return;
        }
    }
    cout << "                        " << "============================ " << endl;
    cout << "                        " << "[ Khong tim thay nhan vien ] " << endl;
    cout << "                        " << "============================ " << endl;
}

void NhanVien::HienThi(const int& i) {
    cout << "| " << i + 1;
    int dem = 0;
    while (1) {
        if (dem < 6 - to_string(i + 1).length()) {
            cout << " ";
            dem++;
        }
        else break;
    }
    cout << "| " << listNV[i].maNV;
    for (int j = 0; j < 13 - listNV[i].maNV.length(); j++) {
        cout << " ";
    }
    cout << "|  " << listNV[i].hoTen;
    for (int j = 0; j < 21 - listNV[i].hoTen.length(); j++) {
        cout << " ";
    }
    cout << "|     " << listNV[i].caLamViec;
    for (int j = 0; j < 11 - listNV[i].caLamViec.length(); j++) {
        cout << " ";
    }
    cout << "|     " << listNV[i].soDT;
    for (int j = 0; j < 14 - listNV[i].soDT.length(); j++) {
        cout << " ";
    }
    cout << "| " << listNV[i].email;
    for (int j = 0; j < 33 - listNV[i].email.length(); j++) {
        cout << " ";
    }
    cout << "|" << endl;
}

void NhanVien::HienThiDanhSachNhanVien() {
    sort(listNV.begin(), listNV.end(), [](const NhanVien& a, const NhanVien& b) {
        return a.caLamViec < b.caLamViec;
    });
    cout << "                                               " << "=======================" << endl;
    cout << "                                               " << "[ Danh sach nhan vien ] " << endl;
    cout << "                                               " << "======================= " << endl;
    cout << "                                               " << "                        " << endl;
    cout << "                                               " << "                        " << endl;

    cout << "|  STT  |      ID      |        Ho va ten      |   Ca lam viec  |   So dien thoai   |               Email              |" << endl;
    for (int i = 0; i < listNV.size(); i++) {
        HienThi(i);
    }
}

void NhanVien::LuuDSNhanVien() {
    ofstream file("data/nhanvien.txt");
    for (int i = 0; i < listNV.size(); i++) {
        file << listNV[i].maNV << ";";
        file << listNV[i].hoTen << ";";
        file << listNV[i].caLamViec << ";";
        file << listNV[i].soDT << ";";
        file << listNV[i].email << endl;
    }
    cout << "                      " << "====================================== " << endl;
    cout << "                      " << "[ Luu danh sach nhan vien thanh cong ]  " << endl;
    cout << "                      " << "====================================== " << endl;

    file.close();
}

void NhanVien::DocDSNhanVien() {
    ifstream file("data/nhanvien.txt");
    if (!file.is_open()) {
        cout << "                       " << "====================================" << endl;
        cout << "                       " << "[ Khong the mo danh sach nhan vien ] " << endl;
        cout << "                       " << "==================================== " << endl;

        return;
    }
    listNV.clear();
    while (file.good()) {
        getline(file, maNV, ';');
        getline(file, hoTen, ';');
        getline(file, caLamViec, ';');
        getline(file, soDT, ';');
        getline(file, email, '\n');
        if (maNV != "") {
            NhanVien nv(maNV, hoTen, caLamViec, soDT, email);
            listNV.push_back(nv);
        }
    }
    cout << "                       " << "====================================== " << endl;
    cout << "                       " << "[ Doc danh sach nhan vien thanh cong ] " << endl;
    cout << "                       " << "====================================== " << endl;

    file.close();
}