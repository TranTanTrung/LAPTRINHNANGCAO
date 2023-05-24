#include <iostream>

using namespace std;

int daonguoc(int n) {
	int a = 0;
	while (n > 0) {
		a = a * 10 + n % 10;
		n = n / 10;
	}
	return a;
}

int main() {
	int n;
	cin >> n;
	cout << n + daonguoc(n);
	return 0;
}