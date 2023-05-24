#include <iostream>

using namespace std;

void nhap(int a[100], int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}
void thaythe(int a[100], int n, int x) {
	int dem = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			cout << "Y" << endl;
			cout << i;
			break;
		}
		if (a[i] > x) {
			a[i] = 0;
		}
		dem++;
	}
	if (dem == n) {
		int max = -99999;
		int z = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > max) {
				max = a[i];
				z = i;
			}
		}
		if (max != -99999) {
			cout << "N" << endl;
			cout << z;
		}
		else {
			cout << "N" << endl;
			cout << "-1";
		}
	}
}

int main() {
	int a[100];
	int n, x;
	cin >> n >> x;
	nhap(a, n);
	thaythe(a, n, x);
	return 0;
}