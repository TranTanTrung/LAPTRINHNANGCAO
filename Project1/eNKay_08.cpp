#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a[10001];
	int n = 0;
	while (cin >> a[n]) {
		if (a[n] == 0) {
			n++;
			break;
		}
		n++;
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[j] == a[i]) {
				a[j] = 0;
			}
		}
	}
	int dem = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			cout << a[i] << " ";
			dem++;
		}
	}
	if (dem == 0) {
		cout << "NOT FOUND";
	}
	return 0;
}