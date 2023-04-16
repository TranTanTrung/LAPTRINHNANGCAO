#include <iostream>

using namespace std;

class PhanSo {
	int tu, mau;
public:
	PhanSo(int _tu = 0, int _mau = 1) {
		tu = _tu;
		mau = _mau;
	}
	PhanSo(const PhanSo& p) {
		tu = p.tu;
		mau = p.mau;
	}
	~PhanSo() {};
	friend istream& operator >> (istream& is, PhanSo& p) {
		is >> p.tu >> p.mau;
		return is;
	}
	friend ostream& operator << (ostream& os, PhanSo& p) {
		PhanSo kq;
		kq = p.RutGon();
		os << kq.tu << "/" << kq.mau << endl;
		return os;
	}
	PhanSo operator + (PhanSo& p) {
		PhanSo kq;
		kq.tu = tu * p.mau + p.tu * mau;
		kq.mau = mau * p.mau;
		return kq;
	}
	PhanSo operator == (PhanSo& p) {
		if (tu == p.tu && mau == p.mau) {
			return true;
		}
		return false;
	}
	PhanSo operator != (PhanSo& p) {
		if (tu != p.mau || mau != p.mau) {
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
	PhanSo RutGon() {
		int a = ucln(tu, mau);
		PhanSo kq;
		kq.tu = tu / a;
		kq.mau = mau / a;
		return kq;
	}
};

int main() {
	PhanSo p, p1, p2;
	cin >> p1 >> p2;
	p = p1 + p2;
	cout << p;
	return 0;
}