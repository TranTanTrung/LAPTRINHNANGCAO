#include <iostream>

using namespace std;

int fibonacy(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	return fibonacy(n - 1) + fibonacy(n - 2);
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << fibonacy(i) << " ";
	}
	return 0;
}