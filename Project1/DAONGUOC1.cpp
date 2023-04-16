#include <iostream>
#include <string>
using namespace std;

int daonguoc(string s) {
	int a = 0;
	char c[100];
	for (int i = 0; i < s.size() ; i++) {
		c[i] = s[i];
	}
	for (int i = s.size()-1; i >= 0; i--) {
		a = a * 10 + int(c[i]-48);
	}
	return a;
}
int dn(int n) {
	int a = 0;
	while (n > 0) {
		a = a * 10 + n % 10;
		n = n / 10;
	}
	return a;
}

int main() {
	string s;
	int max = -9999999;
	while (cin >> s) {
		cin.ignore();
		if (daonguoc(s) > max) {
			max = daonguoc(s);
		}
	}
	cout << dn(max);
	return 0;
}