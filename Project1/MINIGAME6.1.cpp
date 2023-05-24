#include <iostream>

using namespace std;

int main() {
	int a[100], n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int dem=0;
	for (int i = 2; i < n; i++) {
		if (a[i - 1] * a[i + 1] == a[i]) {
			dem++;
		}
	}
	if (dem == 0) {
		cout << "-1";
	}
	else {
		cout << dem << endl;
		for (int i = 2; i < n; i++) {
			if (a[i - 1] * a[i + 1] == a[i]) {
				cout << i << " ";
			}
		}
	}
	return 0;
}