#include <iostream>
#include <cmath>
using namespace std;

double tinh_sinx(double x) {
	double sinx, temp;
	int i = 0;
	sinx = temp = x;
	while (temp > 0.0001 || temp < -0.0001) {
		i++;
		temp = temp * x / (2 * i + 1) * x / (2 * i);
		if (i % 2 == 0) {
			sinx = sinx + temp;
		}
		else {
			sinx = sinx - temp;
		}
	}
	return sinx;
}

int main() {
	double x;
	int i = 0;
	cin >> x;
	double a = sqrt(1 - tinh_sinx(x) * tinh_sinx(x));
	cout << roundf(tinh_sinx(x) * 100) / 100 << endl;
	cout << roundf(a * 100) / 100;
	return 0;
}