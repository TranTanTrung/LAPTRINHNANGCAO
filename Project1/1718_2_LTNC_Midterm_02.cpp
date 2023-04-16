#include <iostream>
#include <string>

using namespace std;

string sapxep(string s) {
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < s.size(); j++) {
			if (s[i] < s[j]) {
				char tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}
		}
	}
	return s;
}

int main() {
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	if (sapxep(s1) == sapxep(s2)) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}