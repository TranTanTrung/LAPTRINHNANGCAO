#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class tinh {
	string mt, tt; // mã tỉnh, tên tỉnh
	int ds; //dân số
	float dt; //diện tích
public:
	tinh(string _mt = "", string _tt = "", int _ds = 0, float _dt = 0) {
		mt = _mt;
		tt = _tt;
		ds = _ds;
		dt = _dt;
	}
	tinh(const tinh& t) {
		mt = t.mt;
		tt = t.tt;
		ds = t.ds;
		dt = t.dt;
	}
	~tinh() {};
	friend istream& operator >> (istream& is, tinh& t) {
		getline(is, t.mt, '_');
		getline(is, t.tt, '_');
		char x;
		is >> t.ds >> x >> t.dt;
		is.ignore();
		return is;
	}
	int get_ds() {
		return ds;
	}
	float get_dt() {
		return dt;
	}
	string get_tt() {
		return tt;
	}
	string get_mt() {
		return mt;
	}
	bool operator > (tinh& t) {
		if (dt > t.dt) {
			return true;
		}
		return false;
	}
	bool operator < (tinh& t) {
		if (dt < t.dt) {
			return true;
		}
		return false;
	}
};

class mang {
	int n;
	tinh t[100];
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
			is >> m.t[i];
		}
		return is;
	}
	void dem_tinh() {
		int dem = 0;
		for (int i = 0; i < n; i++) {
			if (t[i].get_ds() > 1000000) {
				cout << t[i].get_mt() << " ";
				dem++;
			}
		}
		if (dem == 0) {
			cout << dem;
		}
	}
	void dt_max() {
		float max = t[0].get_dt();
		string s1 = t[0].get_tt();
		for (int i = 1; i < n; i++) {
			if (max < t[i].get_dt()) {
				max = t[i].get_dt();
				s1 = t[i].get_tt();
			}
		}
		cout << s1 << endl;
	}
	void sap_xep() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (t[i] > t[j]) {
					tinh tmp = t[i];
					t[i] = t[j];
					t[j] = tmp;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout << t[i].get_mt() << " ";
		}
	}
};

int main() {
	mang m;
	cin >> m;
	m.dem_tinh();
	cout << endl;
	m.dt_max();
	m.sap_xep();
	return 0;
}