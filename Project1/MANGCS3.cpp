#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main() {
	int x;
	cin >> x;
	int n;
	while (cin >> n) {
		v.push_back(n);
	}
	for (int i = x; i < v.size(); i++) {
		v[i] = v[i + 1];
	}
	v.pop_back();
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++) {
		cout << *i << " ";
	}
	return 0;
}