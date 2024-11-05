#ifndef NHAPHANG_H
#define NHAPHANG_H

#include <string>
#include <vector>
#include "NhaCungCap.h"
#include <iostream>
#include <unordered_map>

using namespace std;

class NhapHang {
    private:
        struct SanPhamNhap {
            string maNCC;
            string maSP;
            string tenSP;
            long double tongTien;
            unordered_map<string, int> sanPhamSoLuong;
        };

        vector<SanPhamNhap> dsNH;
        vector<NhaCungCap> danhSachNhaCungCap;

    public:
        NhapHang();
        NhapHang(string maNCC, string maSP, string tenSP, double giaNhap); 
        
        void themSPNhap(NhaCungCap& nhaCungCap);
        void xoaNhapHang(const string& maSP);
        void thayDoiSoLuongNhap(const string& maSP, int soLuongMoi, NhaCungCap& nhaCungCap);
        void timKiemSPNhap();

        void luuNhapHang();
        void docNhapHang();
        void hienThiDanhSachSPNhap();
        double tinhTongTien(const vector<NhaCungCap>& listNCC);
        void tinhTongTienTatCaSanPham();
        void capNhatSoLuongNhaCungCap(const string& maSP, int soLuongXoa);
        double tinhGiaSanPham(const string& maSP);
};

#endif // NHAPHANG_H