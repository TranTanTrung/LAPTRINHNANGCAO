#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main() {
	int n;
	while (cin >> n) {
		v.push_back(n);
	}
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++) {
		cout << *i << " ";
	}
	return 0;
}