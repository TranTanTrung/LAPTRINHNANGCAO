#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	char v[10000];
	int dem = 0, demkc = 1;
	for (int i = 0; i < s.size(); i++) {
		v[i] = s[i];
		if (v[i] == ' ') {
			demkc++;
		}
		dem++;
	}
	while (demkc > 0) {
		int demz = 0;
		for (int i = 0; i < dem; i++) {
			if (v[i] == ' ') {
				demz++;
			}
			if (demz==demkc) {
				cout << v[i];
			}
		}
		demkc--;
	}
	return 0;
}