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
		ps kq = p.RutGon();
		os << kq.tu << "/" << kq.mau;
		return os;
	}
	bool operator == (ps& p) {
		if (tu != p.tu || mau != p.mau) {
			return false;
		}
		return true;
	}
	bool operator == (int n) {
		if (tu == n && mau == 1) {
			return true;
		}
		return false;
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
t tong(t& a, t& b) {
	t tong = a + b;
	return tong;
}

int main() {
	char a[100];
	int sl = 0;
	int tong = 0;
	ps p;
	while (cin >> a[sl]) {
		if (a[sl] == 'a') {
			int x;
			cin >> x;
			tong += x;
		}
		if (a[sl] == 'b') {
			ps p1;
			cin >> p1;
			p = p + p1;
		}
		sl++;
	}
	if (tong == 0 && p == 0) {
		cout << "khong co" << endl;
		cout << "khong co";
	}
	else if (tong == 0) {
		cout << "khong co" << endl;
		cout << p;
	}
	else if (p == 0) {
		cout << tong << endl;
		cout << "khong co";
	}
	else {
		cout << tong << endl;
		cout << p;
	}
	return 0;
}