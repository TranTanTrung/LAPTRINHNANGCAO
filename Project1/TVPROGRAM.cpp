#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[100];
	int dem = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int tong = a[0];
	if (tong > 15) {
		cout << "15";
	}
	else {
		for (int i = 1; i < n; i++) {
			if (a[i] - a[i - 1] > 15) {
				cout << a[i - 1] + 15;
				break;
			}
			else if (90 - a[i] <= 15) {
				cout << a[i];
				break;
			}
			else if (i == n && 90 - a[i] > 15) {
				cout << a[i] + 15;
			}
		}
	}
	return 0;
}