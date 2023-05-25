#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class diem {
	string s;
	float a, b;
public:
	diem(string _s = "", float _a = 0, float _b = 0) {
		s = _s;
		a = _a;
		b = _b;
	}
	diem(const diem& d) {
		s = d.s;
		a = d.a;
		b = d.b;
	}
	~diem() {};
	friend istream& operator >> (istream& is, diem& d) {
		is >> d.s;
		is >> d.a >> d.b;
		return is;
	}
	friend ostream& operator << (ostream& os, diem& d) {
		os << d.s << " " << d.tb() << endl;
		return os;
	}
	float tb() {
		return (a + b) / 2;
	}
};
class mang {
	int n;
	diem d[100];
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
		is.ignore();
		for (int i = 0; i < m.n; i++) {
			is >> m.d[i];
		}
		return is;
	}
	friend ostream& operator << (ostream& os, mang& m) {
		for (int i = 0; i < m.n; i++) {
			for (int j = 0; j < m.n; j++) {
				if (m.d[i].tb() > m.d[j].tb()) {
					diem tmp = m.d[i];
					m.d[i] = m.d[j];
					m.d[j] = tmp;
				}
			}
		}
		for (int i = 0; i < m.n; i++) {
			cout << i + 1 << " " << m.d[i];
		}
		return os;
	}
	void sap_xep_giam_dan() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (d[i].tb() > d[j].tb()) {
					diem tmp = d[i];
					d[i] = d[j];
					d[j] = tmp;
				}
			}
		}
	}
};

int main() {
	mang m;
	cin >> m;
	cout << m;
	return 0;
}