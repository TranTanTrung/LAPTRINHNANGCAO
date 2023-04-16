#include <iostream>

using namespace std;

template <class t>
void sosanh(t& a, t& b) {
	if (a == b) {
		cout << "true";
	}
	else {
		cout << "false";
	}
}
template <class T>
void nhap() {
	T a, b;
	cin >> a >> b;
	sosanh(a, b);
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
		phanso kq = p.rutgon();
		os << kq.tu << "/" << kq.mau;
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
	phanso rutgon() {
		phanso kq;
		int a = ucln(tu, mau);
		kq.tu = tu / a;
		kq.mau = mau / a;
		return kq;
	}
	bool operator == (phanso& p) {
		phanso p1 = this->rutgon();
		phanso p2 = p.rutgon();
		if (p1.tu == p2.tu && p1.mau == p2.mau) {
			return true;
		}
		return false;
	}
};

int main() {
	char x;
	cin >> x;
	if (x == 'a') {
		nhap<int>();
	}
	if (x == 'b') {
		nhap<float>();
	}
	if (x == 'c') {
		nhap<phanso>();
	}
	return 0;
}