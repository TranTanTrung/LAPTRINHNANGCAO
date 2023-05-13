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
};

int main() {
	sv s[100];
	float min = 999;
	int i = 0;
	sv s1;
	while (cin >> s[i]) {
		if (s[i].tb() < min) {
			min = s[i].tb();
			s1 = s[i];
		}
		i++;
	}
	cout << s1;
	return 0;
}