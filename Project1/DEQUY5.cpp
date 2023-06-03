#include <iostream>

using namespace std;

int giaithua(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	else {
		return n * giaithua(n - 1);
	}
}

int main() {
	int n;
	cin >> n;
	cout << giaithua(n);
	return 0;
}