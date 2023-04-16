#include <iostream>
#include <string>

using namespace std;

string xoakhoangtrang(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ' && s[i + 1] == ' ') {
			s.erase(s.begin() + i);
			i--;
		}
	}
	return s;
}

int main() {
	string s;
	while (getline(cin, s)) {
		string s1 = xoakhoangtrang(s);
		int dem = 0;
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] == ' ') {
				dem++;
			}
		}
		cout << dem + 1 << endl;
	}
	return 0;
}