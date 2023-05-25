#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

class thisinh {
	string ht; // họ tên
	int toan, van;
	float tb; // Điểm trung bình
public:
	thisinh(string _ht = "", int _toan = 0, int _van = 0, float _tb = 0) {
		ht = _ht;
		toan = _toan;
		van = _van;
		tb = _tb;
	}
	thisinh(const thisinh& t) {
		ht = t.ht;
		toan = t.toan;
		van = t.van;
		tb = t.tb;
	}
	~thisinh() {};
	int gett() {
		return toan;
	}
	int getv() {
		return van;
	}
	friend istream& operator >> (istream& is, thisinh& t) {
		is.ignore();
		getline(is, t.ht);
		is >> t.toan >> t.van >> t.tb;
		return is;
	}
	friend ostream& operator << (ostream& os, thisinh& t) {
		os << t.ht << " – Toan: " << t.toan << " – Van: " << t.van << " – DiemTB: ";
		os << fixed << setprecision(2) << t.tb << endl;
		return os;
	}
};
class mang {
	int n;
	thisinh t[1000];
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
			os << m.t[i];
		}
		return os;
	}
	void dem_so_HSG() {
		int dem = 0;
		for (int i = 0; i < n; i++) {
			if (t[i].gett() > 8 && t[i].getv() > 8) {
				dem++;
			}
		}
		cout << dem;
	}
};

int main() {
	mang m;
	cin >> m;
	cout << m;
	m.dem_so_HSG();
	return 0;
}