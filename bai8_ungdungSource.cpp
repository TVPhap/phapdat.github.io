#include <iostream> // Thu vien ho tro nhap xuat
using namespace std;

// Ham dao nguoc mang
// Dau vao: arr[] - mang so nguyen; n - so luong phan tu cua mang
void daoNguocMang(int arr[], int n) {
    for (int i = 0; i < n / 2; ++i) { // Lap tu dau den giua mang
        int tam = arr[i]; // Luu phan tu hien tai vao bien tam
        arr[i] = arr[n - i - 1]; // Gan phan tu cuoi vao vi tri hien tai
        arr[n - i - 1] = tam; // Gan phan tu cua bien tam vao vi tri cuoi
    }
}

int main() {
    // Khoi tao mang so nguyen
    int mang[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(mang) / sizeof(mang[0]); // Tinh so luong phan tu trong mang

    // In mang ban dau
    cout << "Mang ban dau: ";
    for (int i = 0; i < n; ++i) {
        cout << mang[i] << " "; // In tung phan tu cua mang
    }
    cout << endl; // Xuong dong

    // Goi ham dao nguoc mang
    daoNguocMang(mang, n);

    // In mang sau khi dao nguoc
    cout << "Mang sau khi dao nguoc: ";
    for (int i = 0; i < n; ++i) {
        cout << mang[i] << " "; // In tung phan tu sau khi da dao nguoc
    }
    cout << endl; // Xuong dong

    return 0; // Ket thuc chuong trinh
}
