#include <iostream>
#include <string>

using namespace std;

class hs {
	string ht;
	float tb;
public:
	hs(string _ht = "", float _tb = 0) {
		ht = _ht;
		tb = _tb;
	}
	hs(const hs& h) {
		ht = h.ht;
		tb = h.tb;
	}
	~hs() {};
	float gettb() {
		return tb;
	}
	string getht() {
		return ht;
	}
	friend istream& operator >> (istream& is, hs& h) {
		getline(is, h.ht);
		is.ignore();
		is >> h.tb;
		return is;
	}
	friend ostream& operator << (ostream& os, hs& h) {
		os << h.ht << endl;
		return os;
	}
};

class lop {
	string ten;
	int n;
	hs h[100];
public:
	lop(string _ten = "", int _n = 0) {
		ten = _ten;
		n = _n;
	}
	lop(const lop& l) {
		ten = l.ten;
		n = l.n;
	}
	~lop() {};
	int getn() {
		return n;
	}
	string getten() {
		return ten;
	}
	friend istream& operator >> (istream& is, lop& l) {
		is >> l.ten;
		is >> l.n;
		is.ignore();
		for (int i = 0; i < l.n; i++) {
			is >> l.h[i];
			is.ignore();
		}
		return is;
	}
	friend ostream& operator << (ostream& os, lop& l) {
		os << l.ten << endl;
		for (int i = 0; i < l.n; i++) {
			os << l.h[i];
		}
		return os;
	}
	string hs_cao_diem_nhat() {
		float max = h[0].gettb();
		string tmp = h[0].getht();
		for (int i = 1; i < n; i++) {
			if (h[i].gettb() > max) {
				max = h[i].gettb();
				tmp = h[i].getht();
			}
		}
		return tmp;
	}
	float diem_lon_nhat() {
		float max = h[0].gettb();
		for (int i = 1; i < n; i++) {
			if (h[i].gettb() > max) {
				max = h[i].gettb();
			}
		}
		return max;
	}
};

class mang {
	int x;
	lop l[1000];
public:
	mang(int _x = 0) {
		x = _x;
	}
	mang(const mang& m) {
		x = m.x;
	}
	~mang() {};
	friend istream& operator >> (istream& is, mang& m) {
		is >> m.x;
		for (int i = 0; i < m.x; i++) {
			is >> m.l[i];
		}
		return is;
	}
	friend ostream& operator << (ostream& os, mang& m) {
		for (int i = 0; i < m.x; i++) {
			os << m.l[i];
			os << endl;
		}
		return os;
	}
	void lop_co_nhieu_hs_nhat() {
		int max = l[0].getn();
		string tmp = l[0].getten();
		int k = 0;
		for (int i = 1; i < x; i++) {
			if (l[i].getn() > max) {
				max = l[i].getn();
				tmp = l[i].getten();
				k = i;
			}
			if (l[i].getn() == max) {
				if (l[i].diem_lon_nhat() > l[k].diem_lon_nhat()) {
					max = l[i].getn();
					tmp = l[i].getten();
					k = i;
				}
			}
		}
		cout << tmp << endl;
		cout << l[k].hs_cao_diem_nhat();
	}
};

int main() {
	mang m;
	cin >> m;
	cout << m;
	m.lop_co_nhieu_hs_nhat();
	return 0;
}