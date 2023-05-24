#include <iostream>

using namespace std;

int main() {
	char a, b;
	cin >> a >> b;
	char x[100];
	x[0] = a;
	for (int i = 1; i < b - a + 1; i++) {
		x[i] = a + i;
	}
	for (int i = 0; i < b - a + 1; i++) {
		if (x[i] >= 97 && x[i] <= 122) {
			x[i] -= 32;
		}
	}
	for (int i = 0; i < b - a + 1; i++) {
		cout << x[i] << " ";
	}
	return 0;
}