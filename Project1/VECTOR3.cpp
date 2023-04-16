#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool kiemtra(int n) {
	if (n < 1) {
		return false;
	}
	int i = sqrt(n);
	if (i * i == n) {
		return true;
	}
	return false;
}
bool sochan(int n) {
	if (n % 2 == 0) {
		return false;
	}
	return true;
}
bool check(int i, int j) {
	return i < j;
}

int main() {
	int n;
	vector<int> v;
	while (cin >> n) {
		v.push_back(n);
	}
	vector<int>::iterator h = remove_if(v.begin(), v.end(), kiemtra);
	v.erase(h, v.end());
	vector<int>::iterator k = remove_if(v.begin(), v.end(), sochan);
	v.erase(k, v.end());
	sort(v.begin(), v.end(), check);
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++) {
		cout << *i << " ";
	}
	return 0;
}