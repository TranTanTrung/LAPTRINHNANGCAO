#include <iostream>

using namespace std;

class dt {
	int a, b, c;
public:
	dt(int _a = 0, int _b = 0, int _c = 0) {
		a = _a;
		b = _b;
		c = _c;
	}
	dt(const dt& d) {
		a = d.a;
		b = d.b;
		c = d.c;
	}
	~dt() {};
	int geta() {
		return a;
	}
	int getb() {
		return b;
	}
	int getc() {
		return c;
	}
	void seta(int x) {
		a = x;
	}
	void setb(int x) {
		b = x;
	}
	void setc(int x) {
		c = x;
	}
	friend istream& operator >> (istream& is, dt& d) {
		is >> d.a >> d.b >> d.c;
		return is;
	}
	friend ostream& operator << (ostream& os, dt& d) {
		if (d.b > 0) {
			if (d.c > 0) {
				os << d.a << "x^2+" << d.b << "x+" << d.c << endl;
			}
			else {
				os << d.a << "x^2+" << d.b << "x" << d.c << endl;
			}
		}
		else {
			if (d.c > 0) {
				os << d.a << "x^2" << d.b << "x+" << d.c << endl;
			}
			else {
				os << d.a << "x^2" << d.b << "x" << d.c << endl;
			}
		}
		return os;
	}
	int tinhGiaTri(int x) {
		return a * x * x + b * x + c;
	}
	dt operator + (dt& d) {
		dt kq;
		kq.a = a + d.a;
		kq.b = b + d.b;
		kq.c = c + d.c;
		return kq;
	}
	bool operator == (dt& d) {
		if (a == d.a && b == d.b && c == d.c) {
			return true;
		}
		return false;
	}
};

class bn {
	int a, b;
public:
	bn(int _a = 0, int _b = 0) {
		a = _a;
		b = _b;
	}
	bn(const bn& bn) {
		a = bn.a;
		b = bn.b;
	}
	~bn() {};
	friend istream& operator >> (istream& is, bn& bn) {
		is >> bn.a >> bn.b;
		return is;
	}
	friend ostream& operator << (ostream& os, bn& bn) {
		if (bn.b > 0) {
			os << "(" << bn.a << "x+" << bn.b << ")";
		}
		else {
			os << "(" << bn.a << "x" << bn.b << ")";
		}
		return os;
	}
	dt operator * (bn& bn) {
		dt kq;
		kq.seta(a * bn.a);
		kq.setb(a * bn.b + b * bn.a);
		kq.setc(b * bn.b);
		return kq;
	}
	int tinhGiaTribn(int x) {
		return a * x + b;
	}
};

int main() {
	dt f1, f2;
	bn f3, f4;
	int n;
	cin >> f1 >> f2 >> f3 >> f4 >> n;
	cout << f1;
	cout << f1.tinhGiaTri(n) << endl;
	cout << f2;
	cout << f2.tinhGiaTri(n) << endl;
	dt f5 = f1 + f2;
	cout << f5;
	cout << f5.tinhGiaTri(n) << endl;
	dt f6 = f3 * f4;
	cout << f3 << "*" << f4 << "=" << f6;
	cout << f6.tinhGiaTri(n) << endl;
	if (f1 == f6 && f2 == f6) {
		cout << "TRUE3";
	}
	else if (f1 == f6) {
		cout << "TRUE1";
	}
	else if (f2 == f6) {
		cout << "TRUE2";
	}
	else {
		cout << "FALSE";
	}
	return 0;
}