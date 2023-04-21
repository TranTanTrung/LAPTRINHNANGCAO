#include <iostream>

using namespace std;

int tong(int n) {
	if (n < 10) {
		return n;
	}
	else {
		return tong(n / 10) + n % 10;
	}
}

int main() {
	long n;
	cin >> n;
	cout << tong(n);
	return 0;
}