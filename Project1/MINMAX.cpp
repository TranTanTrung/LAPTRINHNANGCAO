#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {
	int n;
	while (cin >> n) {
		v.push_back(n);
	}
	sort(v.begin(), v.end());
	cout << v[0] << endl;
	cout << v[v.size() - 1] << endl;
	cout << v[0] + v[v.size() - 1];
	return 0;
}