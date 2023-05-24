#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
    int m;
    cin >> m;
    if (m == 1) {
        int a;
        cin >> a;
        cout << fixed << setprecision(2) << (float)a;
    }
    else if (m == 2) {
        float a;
        int b;
        cin >> a >> b;
        cout << fixed << setprecision(2) << a * b;
    }
    else {
        float x;
        int A, n, a;
        cin >> x >> A >> n >> a;
        float k = x * (float)A + (float)n * (float)a;
        k = (roundf(k * 100)) / 100;
        if (k - 0.005 > 0) {
            cout << fixed << setprecision(2) << k + 0.01;
        }
        else {
            cout << fixed << setprecision(2) << k;
        }
    }
    return 0;
}