#include <iostream>
#include <string>
using namespace std;

class hs { //lớp học sinh
	string ten;
	int tb;
public:
	hs(string _ten = "", int _tb = 0) {
		ten = _ten;
		tb = _tb;
	}
	hs(const hs& h) {
		ten = h.ten;
		tb = h.tb;
	}
	~hs() {};
	friend istream& operator >> (istream& is, hs& h) {
		getline(is, h.ten);
		is >> h.tb;
		return is;
	}
	friend ostream& operator << (ostream& os, hs& h) {
		os << h.ten << " " << h.tb << endl;
		return os;
	}
	int gettb() {
		return tb;
	}
	string getten() {
		return ten;
	}
};
class lop {
	string tenlop;
	int n;
	hs h[100];
public:
	lop(string _tenlop = "", int _n = 0) {
		tenlop = _tenlop;
		n = _n;
	}
	lop(const lop& l) {
		tenlop = l.tenlop;
		n = l.n;
	}
	~lop() {};
	friend istream& operator >> (istream& is, lop& l) {
		//is.ignore();
		getline(is, l.tenlop);
		is >> l.n;
		for (int i = 0; i < l.n; i++) {
			is.ignore();
			is >> l.h[i];
		}
		return is;
	}
	friend ostream& operator << (ostream& os, lop& l) {
		os << l.tenlop << endl;
		for (int i = 0; i < l.n; i++) {
			os << l.h[i];
		}
		return os;
	}
	int getn() {
		return n;
	}
	string get_ten_lop() {
		return tenlop;
	}
	hs hs_cao_diem_nhatlop() {
		hs h1 = h[0];
		for (int i = 1; i < n; i++) {
			if (h[i].gettb() > h1.gettb()) {
				h1 = h[i];
			}
		}
		return h1;
	}
};

class mang {
	int x;
	lop l[100];
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
			is.ignore();
			is >> m.l[i];
		}
		return is;
	}
	friend ostream& operator << (ostream& os, mang& m) {
		for (int i = 0; i < m.x; i++) {
			os << m.l[i];
		}
		return os;
	}
	void lop_nhieu_hs_nhat() {
		int max = l[0].getn();
		string s = l[0].get_ten_lop();
		for (int i = 1; i < x; i++) {
			if (l[i].getn() > max) {
				max = l[i].getn();
				s = l[i].get_ten_lop();
			}
		}
		cout << s << endl;
	}
	void hs_cao_diem_nhat() {
		int max = l[0].hs_cao_diem_nhatlop().gettb();
		string s = l[0].hs_cao_diem_nhatlop().getten();
		for (int i = 1; i < x; i++) {
			if (l[i].hs_cao_diem_nhatlop().gettb() > max) {
				max = l[i].hs_cao_diem_nhatlop().gettb();
				s = l[i].hs_cao_diem_nhatlop().getten();
			}
		}
		cout << s << endl;
	}
};

int main() {
	mang m;
	cin >> m;
	cout << m;
	m.lop_nhieu_hs_nhat();
	m.hs_cao_diem_nhat();
	return 0;
}