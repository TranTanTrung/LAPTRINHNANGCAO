#include <iostream>

using namespace std;

int Day(int n);
int main() {
    int n;
    while (cin >> n) {
        cout << Day(n) << endl;
    }
    return 0;
}
int Day(int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 1;
    }
    else {
        int tong = 0;
        for (int i = 0; i < n; i++) {
            tong += Day(i) * Day(n - 1 - i);
        }
        return tong;
    }
}