#include <iostream>
#include <string>

using namespace std;

class sv {
	string hoten;
	float a, b, c;
public:
	sv(string _hoten = " ", float _a = 0, float _b = 0, float _c = 0) {
		hoten = _hoten;
		a = _a;
		b = _b;
		c = _c;
	}
	sv(const sv& s) {
		hoten = s.hoten;
		a = s.a;
		b = s.b;
		c = s.c;
	}
	~sv() {};
	friend istream& operator >> (istream& is, sv& s) {
		getline(is, s.hoten);
		is >> s.a >> s.b >> s.c;
		is.ignore();
		return is;
	}
	friend ostream& operator << (ostream& os, sv& s) {
		os << s.hoten << endl;
		return os;
	}
	float tb() {
		return (a + b + c) / 3;
	}
	bool operator > (sv& s) {
		if (tb() > s.tb()) {
			return true;
		}
		return false;
	}
};

int main() {
	sv s[100];
	int n = 0;
	while (cin >> s[n]) {
		n++;
	}
	n = n + 1;
	sv s1 = s[0];
	for (int i = 1; i < n; i++) {
		if (s[i] > s1) {
			s1 = s[i];
		}
	}
	cout << s1;
	return 0;
}
