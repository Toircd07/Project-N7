#include "NhapHang.h"
#include "NhaCungCap.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

NhapHang::NhapHang() {}

NhapHang::NhapHang(string maNCC, string maSP, string tenSP, double giaNhap){

}
    // : maNCC(maNCC), maSP(maSP), tenSP(tenSP), tongTien(0) {}

double NhapHang::tinhTongTien(const vector<NhaCungCap>& listNCC) {
    double tongTien = 0;
    for(const auto& nh : dsNH) {
        for(const auto& ncc : listNCC) {
            if (nh.maSP == ncc.getMaSanPham()) {
                tongTien += nh.sanPhamSoLuong.at(nh.maSP) * ncc.getGiaSanPham();
                break;
            }
        }
    }
    return tongTien;
}

void NhapHang::tinhTongTienTatCaSanPham() {
    double tongTien = 0;
    for(const auto& nh : dsNH) {
        tongTien += nh.tongTien;
    }
    cout << "Tong tien tat ca san pham: " << tongTien << endl;
}

void NhapHang::themSPNhap(NhaCungCap& nhaCungCap) {
    // Đảm bảo rằng dữ liệu từ nhà cung cấp được đọc trước khi thêm sản phẩm
    nhaCungCap.docNCC();

    string maSP;
    int soLuong;

    cout << "Nhap ma san pham: ";
    cin >> maSP;
    cout << "Nhap so luong: ";
    cin >> soLuong;

    bool found = false;
    double giaSanPham = 0;
    string maNCC, tenSP;
    for(auto& ncc : nhaCungCap.getDsNCC()) {
        if(ncc.getMaSanPham() == maSP) {
            giaSanPham = ncc.getGiaSanPham();
            tenSP = ncc.getTenSpNhap();
            maNCC = ncc.getMaNCC();
            if(ncc.getSoLuong() >= soLuong) {
                ncc.setSoLuong(ncc.getSoLuong() - soLuong);
                found = true;
                long double tongTien = soLuong * giaSanPham;

                // Kiểm tra xem sản phẩm đã tồn tại trong danh sách hay chưa
                bool productExists = false;
                for(auto& nh : dsNH) {
                    if(nh.maNCC == maNCC && nh.maSP == maSP) {
                        nh.sanPhamSoLuong[maSP] += soLuong;
                        nh.tongTien += tongTien;
                        productExists = true;
                        break;
                    }
                }

                // Nếu sản phẩm chưa tồn tại, thêm sản phẩm mới vào danh sách
                if(!productExists) {
                    SanPhamNhap nh;
                    nh.maNCC = maNCC;
                    nh.maSP = maSP;
                    nh.tenSP = tenSP;
                    nh.tongTien = tongTien;
                    nh.sanPhamSoLuong[maSP] = soLuong;
                    dsNH.push_back(nh);
                }

                cout << "Them san pham thanh cong!" << endl;
                break;
            } else {
                cout << "So luong khong du! So luong hien co: " << ncc.getSoLuong() << endl;
                return;
            }
        }
    }
    if(!found) {
        cout << "Khong tim thay ma san pham!" << endl;
    } else {
        nhaCungCap.luuNCC();
        luuNhapHang();
    }
}

void NhapHang::xoaNhapHang(const string& maSP) {
    bool found = false;
    for (auto it = dsNH.begin(); it != dsNH.end(); ++it) {
        if (it->sanPhamSoLuong.find(maSP) != it->sanPhamSoLuong.end()) {
            int soLuongXoa = it->sanPhamSoLuong[maSP];
            it->tongTien -= soLuongXoa * tinhGiaSanPham(maSP);
            capNhatSoLuongNhaCungCap(maSP, soLuongXoa); 
            it->sanPhamSoLuong.erase(maSP);
            if (it->sanPhamSoLuong.empty()) {
                dsNH.erase(it); 
            }
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Khong tim thay ma san pham!" << endl;
    } else {
        luuNhapHang();
        cout << "Da xoa san pham " << maSP << " va cap nhat so luong trong nha cung cap." << endl;
    }
}

double NhapHang::tinhGiaSanPham(const string& maSP) {
    for(const auto& ncc : danhSachNhaCungCap) {
        if(ncc.getMaSanPham() == maSP) {
            return ncc.getGiaSanPham();
        }
    }
    return 0;
}

void NhapHang::thayDoiSoLuongNhap(const string& maSP, int soLuongMoi, NhaCungCap& nhaCungCap) {
    bool found = false;
    for (auto& nh : dsNH) {
        if (nh.sanPhamSoLuong.find(maSP) != nh.sanPhamSoLuong.end()) {
            int soLuongCu = nh.sanPhamSoLuong[maSP];
            double giaSanPham = tinhGiaSanPham(maSP);

            for (auto& ncc : nhaCungCap.getDsNCC()) {
                if (ncc.getMaSanPham() == maSP) {
                    int soLuongThayDoi = soLuongMoi - soLuongCu;
                    if (soLuongThayDoi > 0 && ncc.getSoLuong() < soLuongThayDoi) {
                        cout << "So luong trong nha cung cap khong du!" << endl;
                        return;
                    }
                    if (soLuongThayDoi < 0 && ncc.getSoLuong() + abs(soLuongThayDoi) < 0) {
                        cout << "So luong trong nha cung cap khong du!" << endl;
                        return;
                    }

                    nh.sanPhamSoLuong[maSP] = soLuongMoi;
                    nh.tongTien = soLuongMoi * giaSanPham; // Cập nhật tổng tiền từ đầu
                    ncc.setSoLuong(ncc.getSoLuong() - soLuongThayDoi); // Cập nhật số lượng trong nhà cung cấp
                    found = true;
                    cout << "So luong san pham " << maSP << " da duoc thay doi thanh " << soLuongMoi << endl;
                    break;
                }
            }
            break;
        }
    }
    if (!found) {
        cout << "Khong tim thay ma san pham!" << endl;
    } else {
        nhaCungCap.luuNCC();
        luuNhapHang();
        tinhTongTienTatCaSanPham(); 
    }
}

void NhapHang::capNhatSoLuongNhaCungCap(const string& maSP, int soLuongThayDoi) {
    for(auto& ncc : danhSachNhaCungCap) {
        if(ncc.getMaSanPham() == maSP) {
            ncc.setSoLuong(ncc.getSoLuong() + soLuongThayDoi); 
            return;
        }
    }
}
void NhapHang::timKiemSPNhap() {
    string maSP;
    cout << "Nhap ma san pham can tim: ";
    cin >> maSP;

    for(const auto& nh : dsNH) {
        for(const auto& spSoLuong : nh.sanPhamSoLuong) {
            if(spSoLuong.first == maSP) {
                cout << "Ma NCC: " << nh.maNCC << endl;
                cout << "Ten SP: " << nh.tenSP << endl;
                cout << "Tong tien:  " << nh.tongTien << "VND" << endl;
                cout << "Ma san pham: " << spSoLuong.first << " - So luong: " << spSoLuong.second << endl;
                return;
            }
        }
    }
    cout << "Khong tim thay san pham!" << endl;
}

void NhapHang::luuNhapHang() {
    ofstream file("data/NhapHang.txt");
    if (!file.is_open()) {
        cerr << "Khong the mo file !" << endl;
        return;
    }

    for(const auto& nh : dsNH) {
        file << nh.maNCC << ";";
        file << nh.maSP << ";";
        file << nh.tenSP << ";";
        file << nh.tongTien << ";";
        for(const auto& spSoLuong : nh.sanPhamSoLuong) {
            file << spSoLuong.first << "," << spSoLuong.second << ";";
        }
        file << endl;
    }
    file.close();
}

void NhapHang::docNhapHang() {
    ifstream file("data/NhapHang.txt");
    if (!file.is_open()) {
        cout << "Khong the mo file !" << endl;
        return;
    }

    dsNH.clear(); 

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string maNCC, maSP, tenSP, tongTienStr;
        getline(ss, maNCC, ';');
        getline(ss, maSP, ';');
        getline(ss, tenSP, ';');
        getline(ss, tongTienStr, ';');

        long double tongTien = 0;
        try {
            tongTien = stold(tongTienStr);
        } catch (const std::invalid_argument& e) {
            cerr << "Loi: Khong the chuyen doi chuoi '" << tongTienStr << "' thanh so." << endl;
            continue; 
        }
        SanPhamNhap nh;
        nh.maNCC = maNCC;
        nh.maSP = maSP;
        nh.tenSP = tenSP;
        nh.tongTien = tongTien;

        string spSoLuongStr;
        while (getline(ss, spSoLuongStr, ';')) {
            stringstream spSoLuongSS(spSoLuongStr);
            string maSP;
            string soLuongStr;
            getline(spSoLuongSS, maSP, ',');
            getline(spSoLuongSS, soLuongStr, ',');
            int soLuong = 0;
            try {
                soLuong = stoi(soLuongStr);
            } catch (const std::invalid_argument& e) {
                cerr << "Loi: Khong the chuyen doi chuoi '" << soLuongStr << "' thanh so." << endl;
                continue; 
            }

            nh.sanPhamSoLuong[maSP] = soLuong;
        }

        dsNH.push_back(nh);
    }
    file.close();
    }

void NhapHang::hienThiDanhSachSPNhap() {
    if(dsNH.empty()) {
        cout << "Chua co san pham nao duoc nhap!" << endl;
        return;
    }

    cout << "------------------- DANH SACH SAN PHAM NHAP -------------------" << endl;
    for(const auto& nh : dsNH) {
        cout << "Ma NCC: " << nh.maNCC << endl;
        cout << "Ten SP: " << nh.tenSP << endl;
        cout << "Tong tien: " << fixed << setprecision(2) << nh.tongTien << endl;
        cout << "Ma san pham - So luong: ";
        for(const auto& spSoLuong : nh.sanPhamSoLuong) {
            cout << spSoLuong.first << " - " << spSoLuong.second << " "; 
        }
        cout << endl;
        cout << "---------------------------------------------------------------" << endl;
    }
    tinhTongTienTatCaSanPham(); 
}