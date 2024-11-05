#ifndef SANPHAM_H // kiem tra xem file SanPham.h da duoc dinh nghia chua
#define SANPHAM_H // dinh nghia file SanPham.h

#include <string>
#include <vector>

using namespace std;

// tao ra 1 class SanPham de quan ly cac chuc nang cua san pham
/* cac thuoc tinh cua san pham duoc 
khai bao private de chi co the truy cap tu ben trong class */
class SanPham{
    private:
        string maSP,tenSP;                 // cac thuoc tinh cua san pham  : ma , ten                            
        double giaBan;                         // gia ban
        int soLuong;                          // so luong                           
        vector<SanPham> listsp;              // tao ra 1 vector de luu tru cac san pham

 // cac phuong thuc cua class duoc khai boa public de co the truy cap tu ben ngoai class                                            
    public:
        SanPham();                          // ham khoi tao mac dinh : cho phep tao doi tuong ma ko can cung cap gia tri ban dau cho cac thuoc tinh doi tuong
        SanPham(string maSP, string tenSP ,double giaBan, int soLuong); // ham khoi tao co tham so
        string getMaSP() const;
        string getTenSP() const;
        double getGiaBan() const;
        int getSoLuong() const;
        void setSoLuong(int soLuong);
        vector<SanPham>& getDsSP(); // Thêm phương thức để truy cập dsSP
        void themSanPham();                  /*cac ham them , sua , xoa , hien thi , tim kiem . luu dssp vao tep txt , doc dssp trong tep txt*/
        void xoaSanPham();
        void suaSanPham();
        void hienThiDanhSachSanPham();
        void timKiemSanPham();
        void luuSanPham();                 
        void docSanPham();
        void hienThi(const int& i);        // ham hien thi thong tin cua san pham tai vi tri i

};

#endif   // ket thuc file SanPham.h

