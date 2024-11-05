#ifndef NHACUNGCAP_H
#define NHACUNGCAP_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NhaCungCap{
    private:
        string maNCC,tenNCC, maSanPham, tenSpNhap;
        double giaSanPham;
        int soLuong;
        vector<NhaCungCap> listNCC;
        vector<pair<string, int>> sanPhamSoLuong; 

    public:
        NhaCungCap();
        NhaCungCap(string maNCC ,string tenNCC,string maSanPham ,string tenSpNhap, int soLuong, double giaSanPham);
        
        string getMaNCC() const;
        string getTenNCC() const;
        string getMaSanPham() const;
        string getTenSpNhap() const;
        int getSoLuong() const;
        void setSoLuong(int soLuong);
        double getGiaSanPham() const;
        vector<NhaCungCap>& getDsNCC();
        vector<pair<string, int>>& getSanPhamSoLuong();

        void themNCC();
        void xoaNCC();
        void suaNCC();
        void hienThidanhsachNCC();
        void timKiemNCC();
        void luuNCC();
        void docNCC();
        void docDuLieuTuFile(const string& filePath);
        void luuDuLieuRaFile(const std::string& filePath);
        void hienThi(const int &i);
        

};

#endif // NHACUNGCAP_H