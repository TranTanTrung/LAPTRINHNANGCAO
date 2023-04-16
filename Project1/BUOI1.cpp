#include <iostream>

using namespace std;

int main() {
	char a[100];
	int n = 0;
	while (cin >> a[n]) {
		n++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] < a[j]) {
				char z = a[i];
				a[i] = a[j];
				a[j] = z;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int k = 0;
		for (int j = i; j <= n; j++) {
			if (a[i] == a[i - 1]) {
				break;
			}
			if (a[i] == a[j]) {
				k++;
			}
			if (a[i] != a[j]) {
				cout << a[i] << ":" << k;
				cout << endl;
				break;
			}
		}
	}
	return 0;
}