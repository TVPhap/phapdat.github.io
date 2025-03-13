#include <iostream>
using namespace std;

// Hàm tính tổng các phần tử trong một dòng
int tinhTongDong(int dong[], int n) {
    int tong = 0;
    for (int i = 0; i < n; ++i) {
        tong += dong[i];
    }
    return tong;
}

// Hàm tìm dòng có tổng lớn nhất
int timDongLonNhat(int maTran[][100], int m, int n) {
    int dongLonNhat = 0;
    int tongLonNhat = tinhTongDong(maTran[0], n);

    for (int i = 1; i < m; ++i) {
        int tongHienTai = tinhTongDong(maTran[i], n);
        if (tongHienTai > tongLonNhat) {
            tongLonNhat = tongHienTai;
            dongLonNhat = i;
        }
    }

    return dongLonNhat;
}

// Hàm sắp xếp ma trận theo tổng các dòng
void sapXepDong(int maTran[][100], int m, int n) {
    for (int i = 0; i < m - 1; ++i) {
        for (int j = i + 1; j < m; ++j) {
            if (tinhTongDong(maTran[i], n) < tinhTongDong(maTran[j], n)) {
                for (int k = 0; k < n; ++k) {
                    swap(maTran[i][k], maTran[j][k]);
                }
            }
        }
    }
}

int main() {
    int m, n;

    cout << "Nhap so dong m và so cot n cua ma tran: ";
    cin >> m >> n;

    int maTran[100][100]; // Giới hạn kích thước ma trận

    cout << "Nhap cac phan tu cua ma tran: " << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> maTran[i][j];
        }
    }

    int dongLonNhat = timDongLonNhat(maTran, m, n);
    cout << "Dong có tong lon nhat la dong " << dongLonNhat + 1 << endl;

    sapXepDong(maTran, m, n);

    cout << "Ma tran sau khi sap xep: " << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << maTran[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
