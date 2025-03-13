#include <iostream>
using namespace std;

struct PhongThi {
    int soPhong;       // Số phòng
    char nha;          // Nhà
    int khaNangChua;   // Khả năng chứa
};

// Hàm hoán đổi hai phòng thi
void hoanDoi(PhongThi& a, PhongThi& b) {
    PhongThi tam = a;
    a = b;
    b = tam;
}

// Hàm sắp xếp theo thứ tự giảm dần về Khả năng chứa
void sapXepGiamDanTheoKhaNangChua(PhongThi ds[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (ds[i].khaNangChua < ds[j].khaNangChua) {
                hoanDoi(ds[i], ds[j]);
            }
        }
    }
}

// Hàm sắp xếp theo thứ tự tăng dần theo Nhà và Số phòng
void sapXepTangDanTheoNhaVaSoPhong(PhongThi ds[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (ds[i].nha > ds[j].nha || (ds[i].nha == ds[j].nha && ds[i].soPhong > ds[j].soPhong)) {
                hoanDoi(ds[i], ds[j]);
            }
        }
    }
}

// Hàm sắp xếp theo thứ tự tăng dần theo Nhà và giảm dần theo Khả năng chứa
void sapXepTangDanTheoNhaGiamDanTheoKhaNangChua(PhongThi ds[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (ds[i].nha > ds[j].nha || (ds[i].nha == ds[j].nha && ds[i].khaNangChua < ds[j].khaNangChua)) {
                hoanDoi(ds[i], ds[j]);
            }
        }
    }
}

// Hàm in danh sách các phòng thi
void inDanhSach(PhongThi ds[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Phong " << ds[i].soPhong << ", Nha " << ds[i].nha << ", Kha nang chua: " << ds[i].khaNangChua << endl;
    }
}

int main() {
    PhongThi ds[] = {
        {101, 'A', 50},
        {102, 'B', 100},
        {103, 'A', 75},
        {104, 'C', 200},
        {105, 'B', 150}
    };
    int n = sizeof(ds) / sizeof(ds[0]);

    // Sắp xếp theo thứ tự giảm dần về Khả năng chứa
    cout << "Danh sach phong thi theo thu tu giam dan ve Kha nang chua:" << endl;
    sapXepGiamDanTheoKhaNangChua(ds, n);
    inDanhSach(ds, n);

    // Sắp xếp theo thứ tự tăng dần theo Nhà và Số phòng
    cout << "\nDanh sach phong thi theo thu tu tang dan theo Nha va So phong:" << endl;
    sapXepTangDanTheoNhaVaSoPhong(ds, n);
    inDanhSach(ds, n);

    // Sắp xếp theo thứ tự tăng dần theo Nhà và giảm dần theo Khả năng chứa
    cout << "\nDanh sach phong thi theo thu tu tang dan theo Nha va giam dan theo Kha nang chua:" << endl;
    sapXepTangDanTheoNhaGiamDanTheoKhaNangChua(ds, n);
    inDanhSach(ds, n);

    return 0;
}