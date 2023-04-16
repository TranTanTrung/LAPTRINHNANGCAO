#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	if (s[0] >= 'a' && s[0] <= 'z') {
		s[0] = s[0] - 32;
	}
	for (int i = 1; i < s.size(); i++) {
		if (s[i - 1] == ' ' && s[i] != ' ') {
			if (s[i] >= 'a' && s[i] <= 'z') {
				s[i] = s[i] - 32;
			}
		}
		if (s[i - 1] != ' ' && s[i] != ' ') {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				s[i] = s[i] + 32;
			}
		}
	}
	cout << s;
	return 0;
}