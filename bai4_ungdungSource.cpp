#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool laSoNguyenTo(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm tìm số nguyên tố lớn nhất trong ma trận
int timSoNguyenToLonNhat(int mat[][100], int m, int n) {
    int maxPrime = -1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (laSoNguyenTo(mat[i][j]) && mat[i][j] > maxPrime) {
                maxPrime = mat[i][j];
            }
        }
    }
    return maxPrime;
}

// Hàm tìm những dòng của ma trận có chứa giá trị nguyên tố
void timDongCoSoNguyenTo(int mat[][100], int m, int n) {
    cout << "Nhung dong co chua gia tri nguyen to: ";
    for (int i = 0; i < m; ++i) {
        bool coSoNguyenTo = false;
        for (int j = 0; j < n; ++j) {
            if (laSoNguyenTo(mat[i][j])) {
                coSoNguyenTo = true;
                break;
            }
        }
        if (coSoNguyenTo) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// Hàm tìm những dòng của ma trận chỉ chứa các số nguyên tố
void timDongChiChuaSoNguyenTo(int mat[][100], int m, int n) {
    cout << "Nhung dong chi chua cac so nguyen to: ";
    for (int i = 0; i < m; ++i) {
        bool chiChuaSoNguyenTo = true;
        for (int j = 0; j < n; ++j) {
            if (!laSoNguyenTo(mat[i][j])) {
                chiChuaSoNguyenTo = false;
                break;
            }
        }
        if (chiChuaSoNguyenTo) {
            cout << i << " ";
        }#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool laSoNguyenTo(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

// Hàm tìm số nguyên tố lớn nhất trong ma trận
int timSoNguyenToLonNhat(int mat[][100], int m, int n) {
    int maxPrime = -1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (laSoNguyenTo(mat[i][j]) && mat[i][j] > maxPrime) {
                maxPrime = mat[i][j];
            }
        }
    }
    return maxPrime;
}

// Hàm tìm những dòng của ma trận có chứa giá trị nguyên tố
void timDongCoSoNguyenTo(int mat[][100], int m, int n) {
    cout << "Nhung dong co chua gia tri nguyen to: ";
    for (int i = 0; i < m; ++i) {
        bool coSoNguyenTo = false;
        for (int j = 0; j < n; ++j) {
            if (laSoNguyenTo(mat[i][j])) {
                coSoNguyenTo = true;
                break;
            }
        }
        if (coSoNguyenTo) {
            cout << i << " ";
        }
    }
    cout << endl;
}

// Hàm tìm những dòng của ma trận chỉ chứa các số nguyên tố
void timDongChiChuaSoNguyenTo(int mat[][100], int m, int n) {
    cout << "Nhung dong chi chua cac so nguyen to: ";
    for (int i = 0; i < m; ++i) {
        bool chiChuaSoNguyenTo = true;
        for (int j = 0; j < n; ++j) {
            if (!laSoNguyenTo(mat[i][j])) {
                chiChuaSoNguyenTo = false;
                break;
            }
        }
        if (chiChuaSoNguyenTo) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    int mat[100][100] = {
        {2, 3, 5, 7},
        {4, 6, 8, 10},
        {11, 13, 17, 19},
        {22, 23, 24, 25}
    };
    int m = 4, n = 4;

    // Tìm số nguyên tố lớn nhất trong ma trận
    int maxPrime = timSoNguyenToLonNhat(mat, m, n);
    if (maxPrime != -1) {
        cout << "So nguyen to lon nhat trong ma tran: " << maxPrime << endl;
    } else {
        cout << "Khong co so nguyen to trong ma tran." << endl;
    }

    // Tìm những dòng của ma trận có chứa giá trị nguyên tố
    timDongCoSoNguyenTo(mat, m, n);

    // Tìm những dòng của ma trận chỉ chứa các số nguyên tố
    timDongChiChuaSoNguyenTo(mat, m, n);

    return 0;
}
    }
    cout << endl;
}

int main() {
    int mat[100][100] = {
        {2, 3, 5, 7},
        {4, 6, 8, 10},
        {11, 13, 17, 19},
        {22, 23, 24, 25}
    };
    int m = 4, n = 4;

    // Tìm số nguyên tố lớn nhất trong ma trận
    int maxPrime = timSoNguyenToLonNhat(mat, m, n);
    if (maxPrime != -1) {
        cout << "So nguyen to lon nhat trong ma tran: " << maxPrime << endl;
    }
    else {
        cout << "Khong co so nguyen to trong ma tran." << endl;
    }

    // Tìm những dòng của ma trận có chứa giá trị nguyên tố
    timDongCoSoNguyenTo(mat, m, n);

    // Tìm những dòng của ma trận chỉ chứa các số nguyên tố
    timDongChiChuaSoNguyenTo(mat, m, n);

    return 0;
}