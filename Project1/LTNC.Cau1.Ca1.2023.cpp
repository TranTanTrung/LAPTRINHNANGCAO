#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

void chuyen_co_so(int n) {
	stack<int> s;
	while (n > 0) {
		if (n % 2 == 0) {
			s.push(0);
		}
		if (n % 2 != 0) {
			s.push(1);
		}
		n = n / 2;
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> v;
	vector<int> v1;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	v1 = v;
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	int max = -999;
	for (int i = 0; i < n; i++) {
		if (v[i] > max) {
			max = v[i];
		}
	}
	cout << endl;
	cout << max << endl;
	chuyen_co_so(max);
	cout << endl;
	int dem = 0;
	vector<int>::iterator it = find(v1.begin(), v1.end(), max);
	while (it != v1.end()) {
		v1.erase(it);
		dem++;
		it = it = find(v1.begin(), v1.end(), max);
	}
	for (vector<int>::iterator i = v1.begin(); i != v1.end(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	cout << dem;
	return 0;
}