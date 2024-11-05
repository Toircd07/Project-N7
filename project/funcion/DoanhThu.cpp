#include "DoanhThu.h"
#include "DonHang.h"
#include "NhaCungCap.h"
#include<string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

long long DoanhThu::tinhTongTienGiaoHangThanhCong(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Khong the mo file: " << filename << endl;
        return 0;
    }

    string line;
    double tongTien = 0;

    while (getline(file, line)) {
        stringstream ss(line);
        string maDH, maKH, ngayTao, trangThai, tongTienStr;
        getline(ss, maDH, ';');
        getline(ss, maKH, ';');
        getline(ss, ngayTao, ';');
        getline(ss, trangThai, ';');
        getline(ss, tongTienStr, ';');

        if (trangThai == "Giao hang thanh cong") {
            try {
                tongTien += stod(tongTienStr);
            } catch (const invalid_argument& e) {
                cerr << "Loi: Gia tri tong tien khong hop le trong dong: " << line << endl;
                continue;
            } catch (const out_of_range& e) {
                cerr << "Loi: Gia tri tong tien vuot qua pham vi cho phep trong dong: " << line << endl;
                continue;
            }
        }
    }

    file.close();
    return tongTien;
}
long long DoanhThu::tinhTongTienSanPhamNhaCungCap(const string& filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Khong the mo file: " << filePath << endl;
        return 0;
    }

    string line;
    long long tongTien = 0;

    while (getline(file, line)) {
        stringstream ss(line);
        string maNCC, tenNCC, maSanPham, tenSpNhap, soLuongStr, giaSanPhamStr;
        getline(ss, maNCC, ';');
        getline(ss, tenNCC, ';');
        getline(ss, maSanPham, ';');
        getline(ss, tenSpNhap, ';');
        getline(ss, soLuongStr, ';');
        getline(ss, giaSanPhamStr, ';');

        try {
            double giaSanPham = stod(giaSanPhamStr);
            int soLuong = stoi(soLuongStr);
            tongTien += giaSanPham * soLuong;
        } catch (const invalid_argument& e) {
            cerr << "Loi: Gia tri khong hop le trong dong: " << line << endl;
            continue;
        } catch (const out_of_range& e) {
            cerr << "Loi: Gia tri vuot qua pham vi cho phep trong dong: " << line << endl;
            continue;
        }
    }

    file.close();
    return tongTien;
}
long long DoanhThu::tinhTongTienSanPhamDangCo(const string& filePath1) {
    ifstream file(filePath1);
    if (!file.is_open()) {
        cerr << "Khong the mo file: " << filePath1 << endl;
        return 0;
    }

    string line;
    long long tongTien = 0;

    while (getline(file, line)) {
        stringstream ss(line);
        string maSP, tenSP, giaBanStr, soLuongStr;
        getline(ss, maSP, ';');
        getline(ss, tenSP, ';');
        getline(ss, giaBanStr, ';');
        getline(ss, soLuongStr, ';');

        try {
            double giaBan= stod(giaBanStr);
            int soLuong = stoi(soLuongStr);
            tongTien += giaBan * soLuong;
        } catch (const invalid_argument& e) {
            cerr << "Loi: Gia tri khong hop le trong dong: " << line << endl;
            continue;
        } catch (const out_of_range& e) {
            cerr << "Loi: Gia tri vuot qua pham vi cho phep trong dong: " << line << endl;
            continue;
        }
    }

    file.close();
    return tongTien;
}