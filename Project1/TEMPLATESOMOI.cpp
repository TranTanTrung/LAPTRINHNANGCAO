#include <iostream>

using namespace std;

class somoi {
	int n;
public:
	somoi(int _n = 0) {
		n = _n;
	}
	somoi(const somoi& s) {
		n = s.n;
	}
	~somoi() {};
	friend istream& operator >> (istream& is, somoi& s) {
		is >> s.n;
		return is;
	}
	friend ostream& operator << (ostream& os, somoi s) {
		os << "[SoMoi] " << s.n << endl;
		return os;
	}
	int tong() {
		int a = n;
		int tong = 0;
		while (a > 0) {
			tong = tong + a % 10;
			a = a / 10;
		}
		return tong;
	}
	bool operator > (somoi& s) {
		if (tong() > s.tong()) {
			return true;
		}
		return false;
	}
	somoi operator + (somoi& s) {
		return tong() + s.tong();
	}
	bool operator == (somoi& s) {
		if (s.n == n) {
			return true;
		}
		return false;
	}
};

template <class t>
class mang {
	int n;
	t a[1000];
public:
	mang<t>(int _n=0) {
		n = _n;
	}
	mang<t>(const mang<t>& m) {
		n = m.n;
	}
	~mang<t>() {};
	friend istream& operator >> (istream& is, mang<t>& m) {
		while (is >> m.a[m.n]) {
			m.n++;
		}
		return is;
	}
	friend ostream& operator << (ostream& os, mang<t>& m) {
		os << m.tim_max() << endl;
		os << m.dem_max() << endl;
		os << m.tong();
		return os;
	}
	t tim_max() {
		t max = a[0];
		for (int i = 1; i < n; i++) {
			if (a[i] > max) {
				max = a[i];
			}
		}
		return max;
	}
	int dem_max() {
		t max = a[0];
		for (int i = 1; i < n; i++) {
			if (a[i] > max) {
				max = a[i];
			}
		}
		int dem = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == max) {
				dem++;
			}
		}
		return dem;
	}
	t tong() {
		t tong = 0;
		for (int i = 0; i < n; i++) {
			tong = tong + a[i];
		}
		return tong;
	}
};

int main() {
	char x;
	cin >> x;
	if (x == 'N') {
		mang<int> m;
		cin >> m;
		cout << m;
	}
	else {
		mang<somoi> m;
		cin >> m;
		cout << m;
	}
	return 0;
}