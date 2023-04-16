#include <iostream>

using namespace std;

template <class t>
t sosanh(t& a, t& b, t& c) {
	t max = a;
	if (max < b) {
		max = b;
	}
	if (max < c) {
		max = c;
	}
	return max;
}
class phanso {
	int tu, mau;
public:
	friend istream& operator >> (istream& is, phanso& p) {
		is >> p.tu >> p.mau;
		return is;
	}
	friend ostream& operator << (ostream& os, phanso& p) {
		os << p.tu << "/" << p.mau;
		return os;
	}
	bool operator < (phanso& p) {
		if (tu * p.mau < p.tu * mau) {
			return true;
		}
		return false;
	}
};
template <class T>
void xuly() {
	T a, b, c;
	cin >> a >> b >> c;
	T x = sosanh<T>(a, b, c);
	cout << x;
}

int main() {
	char x;
	cin >> x;
	if (x == 'a') {
		xuly<int>();
	}
	else if (x == 'b') {
		xuly<float>();
	}
	else {
		/*phanso p1, p2, p3, p4;
		cin >> p1 >> p2 >> p3;
		p4 = sosanh<phanso>(p1, p2, p3);
		cout << p4;*/
		xuly<phanso>();
	}
	return 0;
}