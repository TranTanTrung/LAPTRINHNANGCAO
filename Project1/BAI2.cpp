#include <iostream>

using namespace std;

class ps {
	int tu, mau;
public:
	ps(int _tu = 0, int _mau = 1) {
		tu = _tu;
		mau = _mau;
	}
	~ps() {};
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
	ps rutgon(ps& kq) {
		int a = ucln(tu, mau);
		kq.tu = tu / a;
		kq.mau = mau / a;
		return kq;
	}
	friend istream& operator >> (istream& is, ps& p) {
		is >> p.tu >> p.mau;
		return is;
	}
	friend ostream& operator << (ostream& os, ps& p) {
		p.rutgon(p);
		os << p.tu << "/" << p.mau;
		return os;
	}
	bool operator > (ps& p) {
		if (tu * p.mau > p.tu * mau) {
			return true;
		}
	}
	ps operator = (ps& p) {
		p.tu = tu;
		p.mau = mau;
		return p;
	}
};
class mang {
	int n;
	ps p[100];
public:
	mang(int _n = 0) {
		n = _n;
	}
	~mang() {};
	friend istream& operator >> (istream& is, mang& m) {
		is >> m.n;
		for (int i = 0; i < m.n; i++) {
			is >> m.p[i];
		}
		return is;
	}
	friend ostream& operator << (ostream& os, mang& m) {
		ps kq = m.p[0];
		for (int i = 1; i < m.n; i++) {
			if (kq > m.p[i]) {
				kq = m.p[i];
			}
		}
		os << kq;
		return os;
	}
};

int main() {
	mang m;
	cin >> m;
	cout << m;
	return 0;
}