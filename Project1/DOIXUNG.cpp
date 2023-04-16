#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string xoa(string s) { // xóa khoảng trắng
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			s.erase(s.begin() + i);
		}
	}
	return s;
}
string doi(string s) { // đổi chữ hoa thành chữ thường
	for (int i = 0; i < s.size(); i++) {
		if ('A' <= s[i] && s[i] <= 'Z') {
			s[i] += 32;
		}
	}
	return s;
}
string doixung(string s) {
	reverse(s.begin(), s.end());
	return s;
}
int kiemtra(string s) {
	if (xoa(doi(s)) == doixung(xoa(doi(s)))) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	int n;
	cin >> n;
	cin.ignore();
	string s;
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		cout << kiemtra(s) << endl;
	}
	return 0;
}