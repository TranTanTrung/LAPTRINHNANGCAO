#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> v;

bool kiem_tra(int n) {
	int a = sqrt(n);
	if (a * a == n) {
		return true;
	}
	return false;
}

int main() {
	int n;
	while (cin >> n) {
		v.push_back(n);
	}
	int tong = 0;
	for (int i = 0; i < v.size(); i++) {
		if (kiem_tra(v[i]) == true) {
			tong += v[i];
		}
	}
	cout << tong;
	return 0;
}