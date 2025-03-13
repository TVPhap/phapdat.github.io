#include <iostream>
using namespace std;

// Định nghĩa cấu trúc dữ liệu để lưu trữ thông tin về mỗi số hạng
struct SoHang {
    double heSo; // H? s?
    int bac;     // B?c
};

// Hàm hoán đổi hai số hạng
void hoanDoi(SoHang& a, SoHang& b) {
    SoHang tam = a;
    a = b;
    b = tam;
}

// Hàm sắp xếp các số hạng theo thứ tự tăng dần của các bậc
void sapXepTheoBac(SoHang day[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (day[i].bac > day[j].bac) {
                hoanDoi(day[i], day[j]);
            }
        }
    }
}

/// Hàm tìm vị trí của k phần tử có giá trị lớn nhất
void timViTriLonNhat(int mang[], int n, int k) {
    for (int i = 0; i < k; ++i) {
        int viTriMax = i;
        for (int j = i + 1; j < n; ++j) {
            if (mang[j] > mang[viTriMax]) {
                viTriMax = j;
            }
        }
        cout << viTriMax << " ";
        int tam = mang[i];
        mang[i] = mang[viTriMax];
        mang[viTriMax] = tam;
    }
    cout << endl;
}

int main() {
    // Mảng các số hạng của dãy thức
    SoHang day[] = { {3.5, 2}, {1.2, 0}, {4.8, 3}, {2.1, 1} };
    int n = sizeof(day) / sizeof(day[0]);

    // Sắp xếp các số hạng theo thứ tự tăng dần của các bậc
    sapXepTheoBac(day, n);

    // In ra các số hạng sau khi sắp xếp
    cout << "Cac so hang sau khi sap xep theo thu tu tang dang cua cac bac:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << day[i].heSo << "x^" << day[i].bac << " ";
    }
    cout << endl;

    // Mảng các số nguyên để tìm vị trí của k phần tử có giá trị lớn nhất
    int mang[] = { 56, 23, 89, 12, 34, 45 };
    int m = sizeof(mang) / sizeof(mang[0]);
    int k = 3;

    // Tìm vị trí của k phần tử có giá trị lớn nhất
    cout << "Vi tri cua " << k << " phan tu co gia tri lon nhat: ";
    timViTriLonNhat(mang, m, k);

    return 0;
}