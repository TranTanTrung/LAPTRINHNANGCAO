#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

double GiaiThua(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    else {
        return GiaiThua(n - 1) * n;
    }
}

double LuyThua(int x, int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return LuyThua(x, n - 1) * x;
    }
}

double TinhTong(int n, int x) {
    if (n == 0) {
        return x;
    }
    else {
        return TinhTong(n - 1, x) + (double)(LuyThua(-1, n) * (LuyThua(x, 2 * n + 1) / GiaiThua(2 * n + 1)));
    }
}

int main() {
    int n, x;
    cin >> n >> x;
    double t = TinhTong(n, x);
    cout << roundf(t * 1000) / 1000;
    return 0;
}