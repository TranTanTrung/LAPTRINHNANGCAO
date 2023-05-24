#include <iostream>
#include <iomanip>
using namespace std;

class hcn {
	float x, y;
public:
	hcn(float _x = 0, float _y = 0) {
		x = _x;
		y = _y;
	}
	hcn(const hcn& h) {
		x = h.x;
		y = h.y;
	}
	~hcn() {};
	friend istream& operator >> (istream& is, hcn& h) {
		is >> h.x >> h.y;
		return is;
	}
	float getx() {
		return x;
	}
	float gety() {
		return y;
	}
	friend ostream& operator << (ostream& os, hcn h) {
		os << h.x << "," << h.y;
		return os;
	}
	float chuvi() {
		return (x + y) * 2;
	}
	hcn operator + (hcn& h) {
		hcn kq;
		kq.x = x + h.x;
		kq.y = y + h.y;
		return kq;
	}
	bool operator > (hcn& h) {
		if (chuvi() > h.chuvi()) {
			return true;
		}
		return false;
	}
};

template <class t>
class mang {
	int n;
	t a[10000];
public:
	mang(int _n = 0) {
		n = _n;
	}
	mang(const mang& m) {
		n = m.n;
	}
	~mang() {};
	friend istream& operator >> (istream& is, mang<t>& m) {
		while (is >> m.a[m.n]) {
			m.n++;
		}
		return is;
	}
	friend ostream& operator << (ostream& os, mang<t>& m) {
		os << m.tim_min() << endl;
		return os;
	}
	t tim_min() {
		t min = a[0];
		for (int i = 1; i < n; i++) {
			if (min > a[i]) {
				min = a[i];
			}
		}
		return min;
	}
	t tong() {
		t tong = a[0];
		for (int i = 1; i < n; i++) {
			tong = tong + a[i];
		}
		return tong;
	}
};

int main() {
	char k;
	cin >> k;
	if (k == 'N') {
		mang<int> m;
		cin >> m;
		cout << m;
		cout << m.tong();
	}
	else {
		mang<hcn> m;
		cin >> m;
		cout << "[HCN] " << m;
		hcn h;
		h = m.tong();
		cout << fixed << setprecision(1) << h.chuvi();
	}
	return 0;
}