#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	int n;
	while (cin >> n) {
		v.push_back(n);
	}
	vector<int>::iterator v1;
	for (v1 = v.begin(); v1 != v.end(); v1++) {
		cout << *v1 << " ";
	}
	cout << endl;

	vector<int>::reverse_iterator v2;
	for (v2 = v.rbegin(); v2 != v.rend(); v2++) {
		cout << *v2 << " ";
	}
	return 0;
}
