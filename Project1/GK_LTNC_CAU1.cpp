#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

class diem {
	float a, b, c;
public:
	diem(float _a = 0, float _b = 0, float _c = 0) {
		a = _a;
		b = _b;
		c = _c;
	}
	diem(const diem& d) {
		a = d.a;
		b = d.b;
		c = d.c;
	}
	~diem() {};
	friend istream& operator >> (istream& is, diem& d) {
		is >> d.a >> d.b >> d.c;
		return is;
	}
	friend ostream& operator << (ostream& os, diem& d) {
		os << d.dtb() << endl;
		return os;
	}
	float geta() {
		return a;
	}
	float getb() {
		return b;
	}
	float getc() {
		return c;
	}
	float dtb() {
		return (a + b + c) / 3;
	}
};

class sinhvien {
	string hoten;
	int namsinh;
	diem d;
public:
	sinhvien(string _hoten = "", int _namsinh = 0) {
		hoten = _hoten;
		namsinh = _namsinh;
		//diem[0] = _diem[0];
	}
	sinhvien(const sinhvien& s) {
		hoten = s.hoten;
		namsinh = s.namsinh;
		d = s.d;
		/*for (int i = 0; i < 3; i++) {
			diem[i] = s.diem[i];
		}*/
	}
	~sinhvien() {};
	friend istream& operator >> (istream& is, sinhvien& s) {
		getline(is, s.hoten);
		is >> s.namsinh >> s.d;
		return is;
	}
	friend ostream& operator << (ostream& os, sinhvien& s) {
		os << fixed << setprecision(2);
		float tinh = s.d.dtb();
		os << s.hoten << " - " << s.namsinh << " - " << s.d.dtb() << endl;
		return os;
	}
	bool operator > (sinhvien& s) {
		if (d.dtb() > s.d.dtb()) {
			return true;
		}
		return false;
	}
};

class mang {
	int n;
	sinhvien s[1000];
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
			is >> m.s[i];
			is.ignore();
		}
		return is;
	}
	friend ostream& operator << (ostream& os, mang& m) {
		for (int i = 0; i < m.n; i++) {
			for (int j = 0; j < m.n; j++) {
				if (m.s[i] > m.s[j]) {
					sinhvien tmp = m.s[i];
					m.s[i] = m.s[j];
					m.s[j] = tmp;
				}
			}
		}
		for (int i = 0; i < m.n; i++) {
			os << i + 1 << " - " << m.s[i];
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