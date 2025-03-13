#include <iostream>
using namespace std;

void sapXepChanLe(int arr[], int n) {
    int left = 0;  // Con tr? b?t ??u t? ??u m?ng
    int right = n - 1;  // Con tr? b?t ??u t? cu?i m?ng

    while (left < right) {
        // T�m s? l? b�n tr�i
        while (left < n && arr[left] % 2 == 0) {
            left++;
        }

        // T�m s? ch?n b�n ph?i
        while (right >= 0 && arr[right] % 2 != 0) {
            right--;
        }

        // Ho�n ??i s? l? v� s? ch?n
        if (left < right) {
            swap(arr[left], arr[right]);
        }
    }
}

int main() {
    // Test case m?u
    int mang[] = { 2, 3, 4, 7, 10, 9, 8, 5, 6 };
    int n = sizeof(mang) / sizeof(mang[0]);

    cout << "Mang truoc khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << mang[i] << " ";
    }
    cout << endl;

    // G?i h�m s?p x?p
    sapXepChanLe(mang, n);

    cout << "Mang sau khi sap xep: ";
    for (int i = 0; i < n; i++) {
        cout << mang[i] << " ";
    }
    cout << endl;

    return 0;
}
