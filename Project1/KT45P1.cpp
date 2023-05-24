#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    cout << a % b << endl;
    float y = a * 3.14;
    cout << y << endl;
    double x = ((float)a / 2) * ((float)a / 2) * 3.14;
    cout << x << endl;
    cout << (b + c) * 2 << endl;
    cout << b * c;
    return 0;
}