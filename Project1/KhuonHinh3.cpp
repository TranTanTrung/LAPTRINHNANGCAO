#include <iostream>

using namespace std;

class ps {
	int tu, mau;
public:
	ps(int _tu = 0, int _mau = 1) {
		tu = _tu;
		mau = _mau;
	}
	ps(const ps& p) {
		tu = p.tu;
		mau = p.mau;
	}
	~ps() {};
	friend istream& operator >> (istream& is, ps& p) {
		is >> p.tu >> p.mau;
		return is;
	}
	friend ostream& operator << (ostream& os, ps& p) {
		os << p.tu << "/" << p.mau;
		return os;
	}
	bool operator == (ps& p) {
		if (tu != p.tu || mau != p.mau) {
			return false;
		}
		return true;
	}
	bool operator != (ps& p) {
		if (tu == p.tu && mau == p.mau) {
			return false;
		}
		return true;
	}
	ps operator + (ps& p) {
		ps kq;
		kq.tu = tu * p.mau + p.tu * mau;
		kq.mau = mau * p.mau;
		return kq;
	}
	bool operator < (ps& p) {
		if (tu * p.mau < p.tu * mau) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator == (int n) {
		if (tu == n && mau == 1) {
			return true;
		}
		return false;
	}
	int ucln(int a, int b) {
		while (a * b != 0) {
			if (a > b) {
				a %= b;
			}
			else {
				b %= a;
			}
		}
		return a + b;
	}
	ps RutGon() {
		ps kq;
		int a = ucln(tu, mau);
		kq.tu = tu / a;
		kq.mau = mau / a;
		return kq;
	}
};

template <class t>
t sosanh(t& a, t& b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}

int main() {
	char a[100];
	int sl = 0;
	int min1 = 9999999;
	float min2 = 9999999;
	ps min3 = 999999;
	while (cin >> a[sl]) {
		if (a[sl] == 'a') {
			int x;
			cin >> x;
			if (x < min1) {
				min1 = x;
			}
		}
		else if (a[sl] == 'b') {
			float x;
			cin >> x;
			if (x < min2) {
				min2 = x;
			}
		}
		else {
			ps p1;
			cin >> p1;
			if (p1 < min3) {
				min3 = p1;
			}
		}
		sl++;
	}
	string s;
	s = "khong co";
	if (min1 == 9999999) {
		cout << s << endl;
	}
	else {
		cout << min1 << endl;
	}
	if (min2 == 9999999) {
		cout << s << endl;
	}
	else {
		cout << min2 << endl;
	}
	if (min3 == 999999) {
		cout << s << endl;
	}
	else {
		cout << min3;
	}
	return 0;
}