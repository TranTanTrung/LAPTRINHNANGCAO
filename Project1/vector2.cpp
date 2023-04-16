#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	int n;
	vector<int> v;
	while (cin >> n) {
		v.push_back(n);
	}
	if (s.size() == 1) {
		v.erase(v.begin() + (int(s[0]) - 48));
	}
	else {
		if (s == "-1") {
			v.clear();
			cout << "empty";
			return 0;
		}
		else {
			v.erase(v.begin() + (int(s[0]) - 48), v.begin() + (int(s[2]) - 48));
		}
	}
	for (vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
		cout << *i << " ";
	}
	return 0;
}