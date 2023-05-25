#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class thisinh {
	string ma, ht; //mã thí sinh , họ tên
	float toan, ly, hoa;
public:
	thisinh(string _ma = "", string _ht = "", float _toan = 0, float _ly = 0, float _hoa = 0) {
		ma = _ma;
		ht = _ht;
		toan = _toan;
		ly = _ly;
		hoa = _hoa;
	}
	thisinh(const thisinh& t) {
		ma = t.ma;
		ht = t.ht;
		toan = t.toan;
		ly = t.ly;
		hoa = t.hoa;
	}
	~thisinh() {};
	string getht() {
		return ht;
	}
	friend istream& operator >> (istream& is, thisinh& t) {
		is >> t.ma;
		is.ignore();
		getline(is, t.ht);
		is >> t.toan >> t.ly >> t.hoa;
		return is;
	}
	friend ostream& operator << (ostream& os, thisinh& t) {
		os << t.ma << "-" << t.ht << "-" << t.toan << "-" << t.ly << "-" << t.hoa << endl;
		return os;
	}
	float tong() {
		return toan + ly + hoa;
	}
	bool kiem_tra() {
		if (tong() > 15 && toan > 0 && ly > 0 && hoa > 0) {
			return true;
		}
		return false;
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
	void thi_sinh_vuot_qua() {
		int dem = 0;
		string s1;
		for (int i = 0; i < n; i++) {
			if (t[i].kiem_tra() == true) {
				s1 = s1 + t[i].getht() + "-";
				dem++;
			}
		}
		if (dem == 0) {
			cout << "-1" << endl;
		}
		else {
			for (int i = 0; i < s1.size() - 1; i++) {
				cout << s1[i];
			}
			cout << endl;
		}
	}
	void sap_xep_giam_dan() {
		float a[1000];
		for (int i = 0; i < n; i++) {
			a[i] = t[i].tong();
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (t[i].tong() > t[j].tong()) {
					thisinh tmp = t[i];
					t[i] = t[j];
					t[j] = tmp;
				}
			}
		}
		string s1;
		for (int i = 0; i < n; i++) {
			s1 = s1 + t[i].getht() + "-";
		}
		for (int i = 0; i < s1.size() - 1; i++) {
			cout << s1[i];
		}
	}
};

int main() {
	mang m;
	cin >> m;
	cout << m;
	m.thi_sinh_vuot_qua();
	m.sap_xep_giam_dan();
	return 0;
}