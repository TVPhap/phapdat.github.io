#include <iostream>
#include <cmath>

using namespace std;

// Hàm tính tổng các chữ số của một số
int tongChuSo(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Hàm kiểm tra số nguyên tố
bool laSoNguyenTo(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm tìm vị trí của k phần tử có giá trị lớn nhất
void timKPhanTuLonNhat(int arr[], int n, int k, int viTri[]) {
    for (int i = 0; i < k; ++i) {
        int maxIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] > arr[maxIndex]) {
                maxIndex = j;
            }
        }
        // Hoán đổi phần tử lớn nhất với phần tử tại vị trí hiện tại
        int temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;

        // Lưu vị trí của phần tử lớn nhất
        viTri[i] = maxIndex;
    }
}

// Hàm sắp xếp mảng theo tổng các chữ số
void sapXepTheoTongChuSo(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (tongChuSo(arr[i]) > tongChuSo(arr[j])) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm xóa tất cả các số nguyên tố trong mảng
int xoaSoNguyenTo(int arr[], int n) {
    int newSize = 0;
    for (int i = 0; i < n; ++i) {
        if (!laSoNguyenTo(arr[i])) {
            arr[newSize++] = arr[i];
        }
    }
    return newSize;
}

int main() {
    int arr[] = { 56, 23, 89, 12, 34, 45, 7, 11, 13 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int viTri[100]; // Giả sử mảng không quá 100 phần tử

    // Tìm vị trí của k phần tử có giá trị lớn nhất
    timKPhanTuLonNhat(arr, n, k, viTri);
    cout << "Vi tri cua " << k << "phan tu co gia tri lon nhat: ";
    for (int i = 0; i < k; ++i) {
        cout << viTri[i] << " ";
    }
    cout << endl;

    // Sắp xếp mảng theo tổng các chữ số
    sapXepTheoTongChuSo(arr, n);
    cout << "Day sau khi sap xep theo tong cac chu so: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Xóa tất cả các số nguyên tố trong mảng
    n = xoaSoNguyenTo(arr, n);
    cout << "Day sau khi xoa cac so nguyen to: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}