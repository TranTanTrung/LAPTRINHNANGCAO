#include <iostream>

using namespace std;

class toado {
	int x, y;
public:
	toado(int _x = 0, int _y = 0) {
		x = _x;
		y = _y;
	}
	toado(const toado& t) {
		x = t.x;
		y = t.y;
	}
	~toado() {};
	friend istream& operator >> (istream& is, toado& t) {
		is >> t.x >> t.y;
		return is;
	}
	friend ostream& operator << (ostream& os, toado& t) {
		os << "(" << t.x << "," << t.y << ")";
		return os;
	}
};
class mang {
	int n;
	toado t[100];
public:
	mang(int _n = 0) {
		n = _n;
	}
	mang(const mang& m) {
		n = m.n;
	}
	~mang() {};
	friend istream& operator >> (istream& is, mang& m) {
		is >> m.n;
		for (int i = 0; i < m.n; i++) {
			is >> m.t[i];
		}
		return is;
	}
	friend ostream& operator << (ostream& os, mang& m) {
		for (int i = 0; i < m.n; i++) {
			os << m.t[i] << " ";
		}
		return os;
	}
};

int main() {
	mang m;
	cin >> m;
	cout << m;
	return 0;
}