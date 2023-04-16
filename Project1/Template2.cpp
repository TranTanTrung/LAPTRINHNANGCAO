#include <iostream>

using namespace std;

template <class t>
void tinhtong() {
	t x;
	t tong = 0;
	while (cin >> x) {
		tong = tong + x;
	}
	t y = tong;
	cout<<y;
}
class phanso {
	int tu, mau;
public:
	phanso(int _tu = 0, int _mau = 1) {
		tu = _tu;
		mau = _mau;
	}
	phanso(const phanso& p) {
		tu = p.tu;
		mau = p.mau;
	}
	~phanso() {};
	friend istream& operator >> (istream& is, phanso& p) {
		is >> p.tu >> p.mau;
		return is;
	}
	friend ostream& operator << (ostream& os, phanso& p) {
		phanso kq;
		kq = p.RutGon();
		/*if (kq.tu == kq.mau) {
			os << kq.tu << endl;
		}
		else {*/
			os << kq.tu << "/" << kq.mau;
		//}
		return os;
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
	phanso RutGon() {
		int a = ucln(tu, mau);
		phanso kq;
		kq.tu = tu / a;
		kq.mau = mau / a;
		return kq;
	}
	phanso operator + (phanso& p) {
		phanso kq;
		kq.tu = tu * p.mau + p.tu * mau;
		kq.mau = mau * p.mau;
		return kq;
	}
	phanso operator + (int a) {
		phanso kq;
		kq.tu = tu + a * mau;
		kq.mau = mau;
		return kq;
	}
};

int main() {
	char x;
	cin >> x;
	if (x == 'a') {
		tinhtong<int>();
	}
	else { 
		tinhtong<phanso>();
	}
	return 0;
}