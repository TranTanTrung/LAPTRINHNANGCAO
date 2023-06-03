#include <iostream>
#include <vector>
#include <string>

using namespace std;

class phong {
	string mp, tp; //mã phòng, tên phòng
	float dongia;
	int sl, tt; //Số lượng, tình trạng
public:
	phong(string _mp = " ", string _tp = " ", float _dongia = 0, int _sl = 0, int _tt = 0) {
		mp = _mp;
		tp = _tp;
		dongia = _dongia;
		sl = _sl;
		tt = _tt;
	}
	phong (const phong& p) {
		mp = p.mp;
		tt = p.tt;
		tp = p.tp;
		dongia = p.dongia;
		sl = p.sl;
	}
	~phong() {};
	friend istream& operator >> (istream& is, phong& p) {
		is >> p.mp >> p.tp;
		is >> p.dongia >> p.sl >> p.tt;
		return is;
	}
	friend ostream& operator << (ostream& os, phong& p) {
		os << "Ma Phong: " << p.mp << endl;
		os << "Ten Phong: " << p.tp << endl;
		os << "Don Gia: " << p.dongia << endl;
		os << "So Luong Giuong: " << p.sl << endl;
		os << "Tinh Trang: " << p.tt << endl;
		return os;
	}
	int getsl() {
		return sl;
	}
	bool operator < (phong& p) {
		if (dongia < p.dongia) {
			return true;
		}
		return false;
	}
	int gettt() {
		return tt;
	}
};

int main() {
	vector<phong> v;
	phong p;
	int n;
	cin >> n;
	cin.ignore();
	while (cin >> p) {
		v.push_back(p);
		cin.ignore();
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i].gettt() == 0) {
			cout << v[i];
		}
	}
	int tong = 0;
	for (int i = 0; i < v.size(); i++) {
		tong += v[i].getsl();
	}
	cout << tong << endl;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if (v[i] < v[j]) {
				phong tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	return 0;
}