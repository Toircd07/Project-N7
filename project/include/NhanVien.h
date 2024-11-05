#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>
#include <vector>

using namespace std;

class NhanVien{
private:
    string maNV ;
    string hoTen;
    string caLamViec;
    string soDT;
    string email;
    
    vector<NhanVien> listNV;

public:
    NhanVien();
    NhanVien(string maNV, string hoTen, string caLamViec, string soDT, string email);
    void ThemNhanVien();
    void XoaNhanVien();
    void SuaNhanVien();
    void TimKiemNhanVien();
    void HienThiDanhSachNhanVien();
    void LuuDSNhanVien();
    void DocDSNhanVien();
    void HienThi(const int& i);
};

#endif // NHANVIEN_H