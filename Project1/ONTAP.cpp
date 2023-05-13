#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <queue>

using namespace std;

class phanso {
	int a, b;
public:
	phanso(int _a = 0, int _b = 1) {
		a = _a;
		b = _b;
	}
	phanso(const phanso& p) {
		a = p.a;
		b = p.b;
	}
	~phanso() {};
	friend istream& operator >> (istream& is, phanso& p) {
		string s;
		is >> s;
		int dem = 0;
		p.a = 0;
		p.b = 0;
		queue <char> s1;
		for (int i = 0; i < s.size(); i++) {
			s1.push(s[i]);
		}
		while (!s1.empty()) {
			if (s1.front() == '/') {
				s1.pop();
				break;
			}
			else {
				p.a = p.a * 10 + int(s1.front())-48;
				s1.pop();
			}			
		}
		while (!s1.empty()) {
			p.b = p.b * 10 + int(s1.front())-48;
			s1.pop();
		}
		return is;
	}
	friend ostream& operator << (ostream& os, phanso& p) {
		phanso p1 = p.rutgon();
		if (p1.a == 0) {
			os << "0";
		}
		else {
			if (p1.a == p1.b) {
				os << "1";
			}
			else {
				if (p1.b == 1) {
					os << p1.a;
				}
				else {
					os << p1.a << "/" << p1.b;
				}
			}
		}
		return os;
	}
	bool operator == (phanso& p) {
		if (a == p.a && b == p.b) {
			return true;
		}
		return false;
	}
	bool operator > (phanso& p) {
		if (a * p.b > p.a * b) {
			return true;
		}
		return false;
	}
	bool operator < (phanso& p) {
		if (a * p.b < p.a * b) {
			return true;
		}
		return false;
	}
	int ucln(int x, int y) {
		while (x * y != 0) {
			if (x > y) {
				x %= y;
			}
			else {
				y %= x;
			}
		}
		return x + y;
	}
	phanso rutgon() {
		int x = ucln(a, b);
		phanso kq;
		kq.a = a / x;
		kq.b = b / x;
		return kq;
	}
	phanso operator + (phanso& p) {
		phanso kq;
		kq.a = a * p.b + p.a * b;
		kq.b = b * p.b;
		return kq.rutgon();
	}
};
template <class t>
class mang {
	int n;
	t a[100];
public:
	mang(int _n = 0) {
		n = _n;
	}
	mang(const mang& m) {
		n = m.n;
	}
	~mang() {};
	int getn() {
		return n;
	}
	friend istream& operator >> (istream& is, mang<t>& m) {
		is >> m.n;
		is.ignore();
		for (int i = 0; i < m.n; i++) {
			is >> m.a[i];
		}
		return is;
	}
	friend ostream& operator << (ostream& os, mang<t>& m) {
		for (int i = 0; i < m.n; i++) {
			cout << m.a[i] << " ";
		}
		return os;
	}
	t tongPhanTu() {
		t tong = 0;
		for (int i = 0; i < n; i++) {
			tong = tong + a[i];
		}
		return tong;
	}
	t phanTuMax() {
		t max = -999999;
		for (int i = 0; i < n; i++) {
			if (a[i] > max) {
				max = a[i];
			}
		}
		return max;
	}
	void sapxepchanle() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[j] % 2 != 0) {
					t tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;
				}
			}
		}
		int dem = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] % 2 == 0) {
				dem++;
			}
		}
		sort(a, a + dem);
		sort(a + dem, a + n);
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
	}
	void sapxeplechan() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[j] % 2 == 0) {
					t tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;
				}
			}
		}
		int dem = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] % 2 != 0) {
				dem++;
			}
		}
		for (int i = 0; i < dem; i++) {
			for (int j = 0; j < dem; j++) {
				if (a[i] > a[j]) {
					t tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;
				}
			}
		}
		for (int i = dem; i < n; i++) {
			for (int j = dem; j < n; j++) {
				if (a[i] > a[j]) {
					t tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
	}
	mang<t> operator + (mang<t> &m) {
		int k = 0;
		if (n > m.n) {
			k = n;
		}
		else {
			k = m.n;
		}
		mang<t> kq;
		kq.n = k;
		for (int i = 0; i < kq.n; i++) {
			kq.a[i] = a[i] + m.a[i];
			if (i == n) {
				kq.a[i] = m.a[i];
			}
			if (i == m.n) {
				kq.a[i] = a[i];
			}
		}
		return kq;
	}
	void pssapxep() {
		sort(a, a + n);
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
	}
	void pssapxepgiam() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (a[i] > a[j]) {
					t tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
	}
};

int main() {
	char x;
	cin >> x;
	if (x == 'I') {
		mang<int> m1, m2;
		cin >> m1 >> m2;
		mang<int> m3 = m1 + m2;
		cout << m1 << endl;
		cout << "MAX 1 = " << m1.phanTuMax() << endl;
		cout << "SUM 1 = " << m1.tongPhanTu() << endl;
		m1.sapxepchanle();
		cout << endl << m2 << endl;
		cout << "MAX 2 = " << m2.phanTuMax() << endl;
		cout << "SUM 2 = " << m2.tongPhanTu() << endl;
		m2.sapxeplechan();
		cout << endl << m3;
	}
	else {
		mang<phanso> m1, m2;
		cin >> m1 >> m2;
		mang<phanso> m3 = m1 + m2;
		cout << m1 << endl;
		phanso x = m1.phanTuMax();
		phanso x1 = x.rutgon();
		cout << "MAX 1 = " << x1 << endl;
		phanso y = m1.tongPhanTu();
		cout << "SUM 1 = " << y << endl;
		m1.pssapxep();
		cout << endl << m2 << endl;
		phanso z = m2.phanTuMax();
		cout << "MAX 2 = " << z << endl;
		phanso zz = m2.tongPhanTu();
		cout << "SUM 2 = " << zz << endl;
		m2.pssapxepgiam();
		cout << endl << m3;
	}
	return 0;
}