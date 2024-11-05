#ifndef KhuyenMai_h
#define KhuyenMai_h

#include<string>
#include<vector>

using namespace std;

class KhuyenMai{
    private:
    string maKM;
    string tenKM;
    string ngayBD;
    string ngayKT;
    string phanTramKM;
    int soLuong;
    vector<KhuyenMai> dsKM;
    
    public:
    KhuyenMai();
    KhuyenMai(string maKM, string tenKM, string ngayBD, string ngayKT, string phanTramKM,int soLuong);
    
    void themKM();
    void xoaKM();
    void suaKM();
    void xemDSKM();
    void timKiemKM();
    void docFile();
    void ghiFile();


};
#endif