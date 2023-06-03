#include <iostream>
#include <cmath>
using namespace std;

double TinhTong(int n, int x);
long LuyThua(int x, int n);
long GiaiThua(int n);
int main() {
    int n, x;
    cin >> n >> x;
    cout << roundf(TinhTong(n, x) * 1000) / 1000 << endl;
    return 0;
}
double TinhTong(int n, int x) {
    if (n == 0) {
        return 1 + x;
    }
    else {
        return TinhTong(n - 1, x) + (double)LuyThua(x, 2 * n + 1) / GiaiThua(2 * n + 1);
    }
}
long LuyThua(int x, int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return LuyThua(x, n - 1) * x;
    }
}
long GiaiThua(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return GiaiThua(n - 1) * n;
    }
}