#ifndef DONHANG_H
#define DONHANG_H

#include <string>
#include <vector>
#include "KhachHang.h"
#include "SanPham.h"

using namespace std;

class DonHang {
    private:
        string maDH, maKH, ngayTao, trangThai;
        double tongTien;
        vector<pair<string, int>> sanPhamSoLuong; // danh sach ma sp va so luong trong don hang
        vector<DonHang> dsDH;                    // danh sach don hang                 

    public:
        DonHang();
        DonHang(string maDH, string maKH, string ngayTao, string trangThai = "Dang xu ly");
        void taoDonHang(KhachHang& khachHang, SanPham& sanPham);   // tham chiếu đến khách hàng và sản phẩm liên quan đến đơn hàng
        void suaTrangThaiDonHang(const string& maDH, const string& trangThaiMoi); // tham số truyền vào là mã đơn hàng và trạng thái mới
        void xoaDonHang();
        void timKiemDonHang();
        void suaDonHang();
        void luuDonHang();
        void docDonHang();
        void hienThiDanhSachDonHang(); 
        double tinhTongTien(const vector<SanPham>& danhSachSP);   //
};

#endif // DONHANG_H