#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[100], i = 0;
	while (n > 0) {
		a[i] = n % 10;
		n = n / 10;
	}
	if (i < 4) {
		cout << "-1";
	}
	else {
		cout << a[i];
	}
	return 0;
}