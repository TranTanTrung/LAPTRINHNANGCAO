#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class nhanvien {
	string mnv, tnv;
	float luong;
public:
	nhanvien(string _mnv = "", string _tnv = "", float _luong = 0) {
		mnv = _mnv;
		tnv = _tnv;
		luong = _luong;
	}
	nhanvien(const nhanvien& n) {
		mnv = n.mnv;
		tnv = n.tnv;
		luong = n.luong;
	}
	~nhanvien() {};
	friend istream& operator >> (istream& is, nhanvien& n) {
		getline(is, n.tnv);
		is >> n.mnv;
		is >> n.luong;
		is.ignore();
		return is;
	}
	friend ostream& operator << (ostream& os, nhanvien& n) {
		os << n.tnv << " - " << n.mnv << " - " << n.luong << endl;
		return os;
	}
	float get_luong() {
		return luong;
	}
	string get_tnv() {
		return tnv;
	}
	string get_mnv() {
		return mnv;
	}
	bool operator > (nhanvien& n) {
		if (luong > n.luong) {
			return true;
		}
		return false;
	}
	bool operator < (nhanvien& n) {
		if (luong < n.luong) {
			return true;
		}
		return false;
	}
};

class mang {
	int nn;
	vector<nhanvien> v;
public:
	mang(int _nn = 0) {
		nn = _nn;
	}
	mang(const mang& m) {
		nn = m.nn;
	}
	~mang() {};
	friend istream& operator >> (istream& is, mang& m) {
		is >> m.nn;
		is.ignore();
		nhanvien x;
		for (int i = 0; i < m.nn; i++) {
			is >> x;
			m.v.push_back(x);
		}
		return is;
	}
	friend ostream& operator << (ostream& os, mang& m) {
		for (int i = 0; i < m.v.size(); i++) {
			os << m.v[i];
		}
		return os;
	}
	void luong_max() {
		float max = v[0].get_luong();
		nhanvien n1 = v[0];
		for (int i = 1; i < v.size(); i++) {
			if (max < v[i].get_luong()) {
				max = v[i].get_luong();
				n1 = v[i];
			}
		}
		cout << n1;
	}
	void tong_luong() {
		float tong = 0;
		for (int i = 0; i < v.size(); i++) {
			tong += v[i].get_luong();
		}
		cout << tong << endl;
	}
	void luong_giam_dan() {
		for (int i = 0; i < v.size(); i++) {
			for (int j=0; j < v.size(); j++) {
				if (v[i] > v[j]) {
					nhanvien temp = v[i];
					v[i] = v[j];
					v[j] = temp;
				}
			}
		}
		for (int i = 0; i < v.size(); i++) {
			cout << v[i];
		}
	}
};

int main() {
	mang m;
	cin >> m;
	cout << m;
	m.luong_max();
	m.tong_luong();
	m.luong_giam_dan();
	return 0;
}