#ifndef DOANHTHU_H
#define DOANHTHU_H

#include <string>

using namespace std;

class DoanhThu {
public:
    static long long tinhTongTienGiaoHangThanhCong(const string& filename);
    static long long tinhTongTienSanPhamNhaCungCap(const string& filePath);
    static long long tinhTongTienSanPhamDangCo    (const string& filePath1);
};

#endif // DOANHTHU_H