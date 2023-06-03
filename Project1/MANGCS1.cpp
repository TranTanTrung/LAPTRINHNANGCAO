//#include <iostream>
//
//using namespace std;
//
//int main() {
//	int a[100];
//	int x, y;
//	cin >> x >> y;
//	int n = 0;
//	while (cin >> a[n]) {
//		n++;
//	}
//	n++;
//	for (int i = n - 1; i > x - 1; i--) {
//		a[i + 1] = a[i];
//	}
//	a[x] = y;
//	for (int i = 0; i < n; i++) {
//		cout << a[i] << " ";
//	}
//	return 0;
//}

#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main() {
	int x, y;
	cin >> x >> y;
	int n;
	while(cin >> n) {
		v.push_back(n);
	}
	v.push_back(0);
	for (int i = v.size() - 1; i > x - 1; i--) {
		v[i + 1] = v[i];
	}
	v[x] = y;
	for (vector<int>::iterator i = v.begin(); i != v.end(); i++) {
		cout << *i << " ";
	}
	return 0;
}