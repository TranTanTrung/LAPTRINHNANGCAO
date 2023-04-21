#include <iostream>
#include <string>
using namespace std;

bool isPalindrom(string s) {
	int len = s.length();
	if (len <= 1) {
		return true;
	}
	if (s[0] != s[len - 1]) {
		return false;
	}
	return isPalindrom(s.substr(1, len - 2));
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string m;
		cin >> m;
		if (isPalindrom(m)) {
			cout << m << " ";
		}
	}
	return 0;
}