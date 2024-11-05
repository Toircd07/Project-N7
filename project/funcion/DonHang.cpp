#include "DonHang.h"
#include "SanPham.h"
#include "KhachHang.h"
#include <fstream>
#include <iostream>
#include <sstream>

DonHang::DonHang() : trangThai("Dang xu ly"), tongTien(0) {}

DonHang::DonHang(string maDH, string maKH, string ngayTao, string trangThai)
    : maDH(maDH), maKH(maKH), ngayTao(ngayTao), trangThai(trangThai), tongTien(0) {}

void DonHang::taoDonHang(KhachHang& khachHang, SanPham& sanPham) {
    string maDH, maKH, maSP, ngayTao;
    int soLuong;

    cout << "Nhap ma don hang: ";
    cin >> maDH;
    cout << "Nhap ma khach hang: ";
    cin >> maKH;
    cout << "Nhap ngay tao don hang: ";
    cin >> ngayTao;

    DonHang dh(maDH, maKH, ngayTao); 

    while (true) {
        cout << "Nhap ma san pham (nhap 'x' de ket thuc): ";
        cin >> maSP;
        if (maSP == "x") break;

        cout << "Nhap so luong: ";
        cin >> soLuong;

        bool sanPhamTonTai = false;     
        for (auto& sp : sanPham.getDsSP()) {   // duyet qua danh sach san pham
            if (sp.getMaSP() == maSP) {           // kt xem msp co ton tai trong ds san pham hay khong
                if (sp.getSoLuong() >= soLuong) {     
                    sp.setSoLuong(sp.getSoLuong() - soLuong);    // neu so luong san pham du thi tru so luong san pham do di
                    dh.sanPhamSoLuong.push_back(make_pair(maSP, soLuong));   // them ma sp va so luong vao ds san pham so luong
                    sanPhamTonTai = true;
                    break;
                } else {
                    cout <<"                   "<< "===============================" << endl;   
                    cout <<"                   "<< "[ So luong san pham khong du! ]" << endl;
                    cout <<"                   "<< "===============================" << endl;
                    sanPhamTonTai = true;
                    break;
                }
            }
        }
        if (!sanPhamTonTai) {
            cout <<"                   "<< "============================" << endl;   
            cout <<"                   "<< "[ Khong tim thay san pham! ]" << endl;
            cout <<"                   "<< "============================" << endl;   
        }
    }

    dh.tongTien = dh.tinhTongTien(sanPham.getDsSP());   // tinh tong tien cua don hang
    dsDH.push_back(dh);                                        // them don hang vao ds don hang
    luuDonHang();

    sanPham.luuSanPham();

    for (auto& kh : khachHang.getDsCus()) {           // duyet qua danh sach khach hang
        if (kh.getMaCus() == maKH) {                  // kt xem makh co ton tai trong ds khach hang hay khong
            kh.tangDiemTichLuy(5);                      // neu co thi tang diem tich luy cho khach hang len 5
            khachHang.luuDSCus();                       // luu ds khach hang
            break;
        }
    }

            cout <<"                   "<< "===========================" << endl;   
            cout <<"                   "<< "[ Tao don hang thanh cong ]" << endl;
            cout <<"                   "<< "===========================" << endl;   
}

void DonHang::suaTrangThaiDonHang(const string& maDH, const string& trangThaiMoi) {       
    bool found = false; // Biến để kiểm tra xem đơn hàng có được tìm thấy hay không
    for (auto& dh : dsDH) {
        if (dh.maDH == maDH) {
            dh.trangThai = trangThaiMoi;

            cout <<"                   "<< "===========================================" << endl;   
            cout <<"                   "<< "[ Cap nhat trang thai don hang thanh cong ]" << endl;
            cout <<"                   "<< "===========================================" << endl; 
            found = true; 
            break; // Thoát khỏi vòng lặp sau khi tìm thấy và cập nhật đơn hàng
        }
    }
    if (!found) {
            cout <<"                   "<< "============================" << endl;   
            cout <<"                   "<< "[ Khong tim thay don hang! ]" << endl;
            cout <<"                   "<< "============================" << endl; 
    }
    luuDonHang(); // Lưu danh sách đơn hàng sau khi cập nhật
}

void DonHang::xoaDonHang() {
    cout << "Nhap ma don hang can xoa: ";
    cin >> maDH;
    for(int i = 0; i < dsDH.size(); i++){
        if(dsDH[i].maDH == maDH){
            dsDH.erase(dsDH.begin() + i);   // xoa don hang tai vi tri i
            cout <<"                   "<< "===========================" << endl;   
            cout <<"                   "<< "[ Xoa don hang thanh cong ]" << endl;
            cout <<"                   "<< "===========================" << endl; 
            luuDonHang();   // luu lai danh sach don hang sau khi xoa
            return;
        }
    }
            cout <<"                   "<< "============================" << endl;   
            cout <<"                   "<< "[ Khong tim thay don hang  ]" << endl;
            cout <<"                   "<< "============================" << endl; 
}
// Ham tim kiem don hang
void DonHang::timKiemDonHang() {
    string maDH;
    string maKH ;
    cout << "Nhap ma don hang can tim: ";
    cin >> maDH;
            cout << "    "<<"Thong tin don hang"      << endl;
            cout << "-------------------------------" << endl;
    for (int i = 0; i < dsDH.size(); i++) {
        if (dsDH[i].maDH == maDH) {
            cout << "[Thong tin don hang]" << endl;
            cout << "Ma don hang: " << dsDH[i].maDH << endl;
            cout << "Ma khach hang: " << dsDH[i].maKH << endl;
            cout << "Ngay tao: " << dsDH[i].ngayTao << endl;
            cout << "Trang thai: " << dsDH[i].trangThai << endl;
            cout << "Tong tien: " << dsDH[i].tongTien << endl;
            cout << "San pham - so luong:" << endl;
            for (const auto& spSoLuong : dsDH[i].sanPhamSoLuong) {
                cout << "  " << spSoLuong.first << " - " << spSoLuong.second << endl;
            }
              
            cout << "-----------------------------" << endl;
            return;
        }
    }
            cout <<"                   "<< "============================" << endl;   
            cout <<"                   "<< "[ Khong tim thay don hang  ]" << endl;
            cout <<"                   "<< "============================" << endl; 
}

void DonHang::luuDonHang() {
    ofstream file("data/donhang.txt");
    for (const auto& dh : dsDH) {
        file << dh.maDH << ";" ;
        file << dh.maKH << ";" ;
        file << dh.ngayTao << ";" ;
        file << dh.trangThai << ";" ;
        file << dh.tongTien << ";";
        for (const auto& spSoLuong : dh.sanPhamSoLuong) {
            file << spSoLuong.first << "," << spSoLuong.second << ";";
        }
        file << endl;
    }
            cout <<"                   "<< "=================================" << endl;   
            cout <<"                   "<< "[  Luu file don hang thanh cong ]" << endl;
            cout <<"                   "<< "=================================" << endl; 
    file.close();
}

void DonHang::docDonHang() {
    ifstream file("data/donhang.txt");
    if (!file.is_open()) {
        cout << "Khong the mo file don hang!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string maDH, maKH, ngayTao, trangThai, tongTienStr, sanPhamSoLuongStr;
        
        getline(ss, maDH, ';');
        getline(ss, maKH, ';');
        getline(ss, ngayTao, ';');
        getline(ss, trangThai, ';');
        getline(ss, tongTienStr, ';');
        double tongTien = stod(tongTienStr);

        vector<pair<string, int>> sanPhamSoLuong;
        while (getline(ss, sanPhamSoLuongStr, ';')) {
            size_t pos = sanPhamSoLuongStr.find(',');
            if (pos == string::npos) {
                cout << "Loi: Khong the tim thay dau phay trong chuoi '" << sanPhamSoLuongStr << "'." << endl;
                continue;
            }
            string maSP = sanPhamSoLuongStr.substr(0, pos);
            int soLuong = stoi(sanPhamSoLuongStr.substr(pos + 1));
            sanPhamSoLuong.push_back(make_pair(maSP, soLuong));
        }

        DonHang dh(maDH, maKH, ngayTao, trangThai);
        dh.tongTien = tongTien;
        dh.sanPhamSoLuong = sanPhamSoLuong;
        dsDH.push_back(dh);
    }

            cout <<"                   "<< "=================================" << endl;   
            cout <<"                   "<< "[  Doc file don hang thanh cong ]" << endl;
            cout <<"                   "<< "=================================" << endl; 
    file.close();
}

void DonHang::hienThiDanhSachDonHang() {
        cout << "------------------------------------------------------------" << endl;
        cout << "                 "<< " Danh sach don hang " <<"             " << endl;
        cout << "------------------------------------------------------------" << endl;
    for (const auto& dh : dsDH) {
        cout << "Ma don hang: " << dh.maDH << endl;
        cout << "Ma khach hang: " << dh.maKH << endl;
        cout << "Ngay tao: " << dh.ngayTao << endl;
        cout << "Trang thai: " << dh.trangThai << endl;
        cout << "Tong tien: " << dh.tongTien << endl;
        cout << "San pham: " << endl;
        for (const auto& spSoLuong : dh.sanPhamSoLuong) {
            cout << "  Ma san pham: " << spSoLuong.first << ", So luong: " << spSoLuong.second << endl;
        }
        cout << "------------------------------------------------------------" << endl;
    }
}

void DonHang::suaDonHang() {
    string maDH;
    cout << "Nhap ma don hang can sua: ";
    cin >> maDH;
    cin.ignore(); // Bỏ qua ký tự newline còn lại trong bộ đệm

    for (auto& dh : dsDH) {
        if (dh.maDH == maDH) {
            cout << "Nhap ma khach hang moi (hien tai: " << dh.maKH << "): ";
            getline(cin, dh.maKH);

            cout << "Nhap ngay tao moi (hien tai: " << dh.ngayTao << "): ";
            getline(cin, dh.ngayTao);

            cout << "Nhap trang thai moi (hien tai: " << dh.trangThai << "): ";
            getline(cin, dh.trangThai);

            dh.sanPhamSoLuong.clear();
            cout << "Nhap danh sach san pham moi (maSP,soLuong), ket thuc bang dau cham (.)" << endl;
            while (true) {
                string sanPhamSoLuongStr;
                cout << "Nhap san pham va so luong: ";
                getline(cin, sanPhamSoLuongStr);
                if (sanPhamSoLuongStr == "x") break;

                size_t pos = sanPhamSoLuongStr.find(',');
                if (pos == string::npos) {
                    cout << "Loi: Khong the tim thay dau phay trong chuoi '" << sanPhamSoLuongStr << "'x" << endl;
                    continue;
                }
                string maSP = sanPhamSoLuongStr.substr(0, pos);
                int soLuong = stoi(sanPhamSoLuongStr.substr(pos + 1));
                dh.sanPhamSoLuong.push_back(make_pair(maSP, soLuong));
            }

            cout <<"                   "<< "============================" << endl;   
            cout <<"                   "<< "[  Sua don hang thanh cong ]" << endl;
            cout <<"                   "<< "============================" << endl; 
            return;
        }
    }
            cout <<"                   "<< "============================" << endl;   
            cout <<"                   "<< "[  Khong tim thay don hang ]" << endl;
            cout <<"                   "<< "============================" << endl; 
}
double DonHang::tinhTongTien(const vector<SanPham>& danhSachSP) {
    double tongTien = 0;
    for (const auto& spSoLuong : sanPhamSoLuong) {
        for (const auto& sp : danhSachSP) {
            if (sp.getMaSP() == spSoLuong.first) {
                tongTien += sp.getGiaBan() * spSoLuong.second;
                break;
            }
        }
    }
    return tongTien;
}