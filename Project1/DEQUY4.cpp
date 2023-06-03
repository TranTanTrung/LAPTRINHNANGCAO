#include <iostream>
#include <cmath>

using namespace std;

int de_quy(int n, int x) {
    if (n == 1) {
        return 1 + x;
    }
    else {
        return de_quy(n - 1, x) + pow(x, n);
    }
}

int main() {
    int n, x;
    cin >> n >> x;
    cout << de_quy(n, x);
    return 0;
}