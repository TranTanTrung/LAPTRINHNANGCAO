#include <iostream>

using namespace std;

int ucln_de_quy(int a, int b) {
	if (b == 0) {
		return a;
	}
	if (a % b == 0) {
		return b;
	}
	else {
		return ucln_de_quy(b, a % b);
	}
}

int ucln_binh_thuong(int a, int b) {
	while (a * b != 0) {
		if (a > b) {
			a %= b;
		}
		else {
			b %= a;
		}
	}
	return a + b;
}

int main() {
	int a, b;
	cin >> a >> b;
	cout << ucln_de_quy(a, b) << endl;
	cout << ucln_binh_thuong(a, b);
	return 0;
}