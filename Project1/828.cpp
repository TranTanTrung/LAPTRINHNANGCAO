#include <iostream>
#include <string>

using namespace std;

class sach {
	string ten, tg;
	int nam;
public:
	sach(string _ten = "", string _tg = "", int _nam = 0) {
		ten = _ten;
		tg = _tg;
		nam = _nam;
	}
	sach(const sach& s) {
		ten = s.ten;
		tg = s.tg;
		nam = s.nam;
	}
	~sach() {};
	int getnam() {
		return nam;
	}
	friend istream& operator >>(istream& is, sach& s) {
		is.ignore();
		getline(is, s.ten);
		getline(is, s.tg);
		is >> s.nam;
		return is;
	}
	friend ostream& operator << (ostream& os, sach& s) {
		os << s.ten << endl;
		os << s.tg << endl;
		os << s.nam << endl;
		return os;
	}
};

class mang {
	int n;
	sach s[100];
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
			is >> m.s[i];
		}
		return is;
	}
	void sach_cu_nhat() {
		int min = s[0].getnam();
		sach s1 = s[0];
		for (int i = 1; i < n; i++) {
			if (min > s[i].getnam()) {
				min = s[i].getnam();
				s1 = s[i];
			}
		}
		cout << s1;
	}
	int nam_nhieu_sach_nhat() {
		int dem1 = -999;
		int tmp = 0;
		for (int i = 0; i < n; i++) {
			int dem = 0;
			for (int j = 0; j < n; j++) {
				if (s[i].getnam() == s[j].getnam()) {
					dem++;
				}
			}
			if (dem > dem1) {
				dem = dem1;
				tmp = s[i].getnam();
			}
		}
		return tmp;
	}
	void sach_trong_nam_nhieu_sach() {
		int a = nam_nhieu_sach_nhat();
		for (int i = 0; i < n; i++) {
			if (s[i].getnam() == a) {
				cout << s[i];
			}
		}
	}
};

int main() {
	mang m;
	cin >> m;
	m.sach_cu_nhat();
	cout << m.nam_nhieu_sach_nhat() << endl;
	m.sach_trong_nam_nhieu_sach();
	return 0;
}