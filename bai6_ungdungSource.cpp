#include <iostream>
using namespace std;

// Hàm kiểm tra số chẵn
bool laSoChan(int so) {
    return so % 2 == 0 && so != 0;
}

// Hàm kiểm tra số lẻ
bool laSoLe(int so) {
    return so % 2 != 0;
}

int main() {
    // Mảng ví dụ
    int mang[] = { 0, 5, 8, 0, 3, 6, 9, 0, 12, 4, 7, 10, 0 };
    int n = sizeof(mang) / sizeof(mang[0]);

    // Sắp xếp các số chẵn tăng dần
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (laSoChan(mang[i]) && laSoChan(mang[j]) && mang[i] > mang[j]) {
                swap(mang[i], mang[j]);
            }
        }
    }

    // Sắp xếp các số lẻ giảm dần
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (laSoLe(mang[i]) && laSoLe(mang[j]) && mang[i] < mang[j]) {
                swap(mang[i], mang[j]);
            }
        }
    }

    // Xuất kết quả
    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << mang[i] << " ";
    }
    cout << endl;

    return 0;
}
