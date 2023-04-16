#include <iostream>

using namespace std;

class ps {
	int tu, mau;
public:
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
		if (p.mau == 0) {
			os << "-1";
		}
		else {
			p.rutgon(p);
			os << p.tu << "/" << p.mau;
		}
		return os;
	}
	ps tong(ps& p) {
		ps kq;
		kq.tu = tu * p.mau + p.tu * mau;
		kq.mau = mau * p.mau;
		return kq;
	}
};

int main() {
	ps p1, p2, p;
	cin >> p1 >> p2;
	p = p1.tong(p2);
	cout << p;
	return 0;
}