#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int n, k;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> k;
		v.push_back(k);
	}
	int a, b;
	while (cin >> a) {
		if (a == -1) {
			v.clear();
		}
		else if (cin >> b) {
			v.erase(v.begin() + a, v.begin() + b);
		}
		else {
			v.erase(v.begin() + a);
		}
	}
	if (v.empty()) {
		cout << "empty";
	}
	else {
		for (vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
			cout << *i << " ";
		}
	}
	return 0;
}