#include <iostream>
#include <string>
using namespace std;

class chuoi {
	string s;
public: 
	chuoi(string _s = "") {
		s = _s;
	}
	chuoi(const chuoi& c) {
		s = c.s;
	}
	~chuoi() {};
	friend istream& operator >> (istream& is, chuoi& c) {
		getline(is, c.s);
		return is;
	}
	friend ostream& operator << (ostream& os, chuoi& c) {
		os << c.s << endl;
		return os;
	}
	int getStringLength() {
		return s.size();
	}
	chuoi stringUpperCase() {
		string kq = s;
		for (int i = 0; i < kq.size(); i++) {
			if (kq[i] >= 97 && kq[i] <= 122) {
				kq[i] = kq[i] - 32;
			}
		}
		return kq;
	}
	string gets() {
		return s;
	}
	void sets(string _s="") {
		s = _s;
	}
	bool operator > (chuoi& c) {
		if (s.size() > c.s.size()) {
			return true;
		}
		return false;
	}
};

int main() {
	chuoi s1, s2;
	cin >> s1 >> s2;
	cout << s1 << s2;
	if (s1 > s2) {
		cout << "YES" << endl;
		chuoi s3 = s1.stringUpperCase();
		cout << s3;
	}
	else {
		cout << "NO" << endl;
		chuoi s3 = s2.stringUpperCase();
		cout << s3;
	}
	return 0;
}