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
};

int main() {
	ps p;
	cin >> p;
	cout << p;
	return 0;
}
