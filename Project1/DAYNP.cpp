// Cách 1 không dùng đệ quy
#include <iostream>
#include <cmath>
using namespace std;

int N;

int x[100];

string chuyen_so(int n) { //chuyển số thập phân sang số nhị phân
	string s = "";
	while (n > 0) {
		s = char(n % 2 + '0') + s;
		n = n / 2;
	}
	while (s.size() < N) {
		s = '0' + s;
	}
	return s;
}

int main() {
	cin >> N;
	int N_2 = pow(2, N);
	for (int i = 0; i < N_2; i++) {
		cout << chuyen_so(i) << endl;
	}
	return 0;
}

// Cách 2 dùng quay lui
#include <iostream>

using namespace std;

int N;

int a[100];

void in(int a[]) {
	for (int i = 1; i <= N; i++) {
		cout << a[i];
	}
	cout << endl;
}

void DeQuy(int i) {
	for (int j = 0; j <=1 ; j++) {
		a[i] = j;
		if (i == N) {
			in(a);
		}
		else {
			DeQuy(i + 1);
		}
	}
}

int main() {
	cin >> N;
	DeQuy(1);
	return 0;
}