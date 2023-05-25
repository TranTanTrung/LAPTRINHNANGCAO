#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class sapxep {
	string s;
	int n;
public:
	sapxep(string _s = " ", int _n = 0) {
		s = _s;
		n = _n;
	}
	sapxep(const sapxep& sa) {
		s = sa.s;
		n = sa.n;
	}
	~sapxep() {};
	friend istream& operator >> (istream& is, sapxep& sa) {
		is >> sa.s >> sa.n;
		is.ignore();
		return is;
	}
	friend ostream& operator << (ostream& os, sapxep& sa) {
		os << sa.s << endl;
		return os;
	}
	bool operator < (sapxep& sa) {
		if (n < sa.n) {
			return true;
		}
		return false;
	}
	bool operator == (sapxep& sa) {
		if (n == sa.n) {
			return true;
		}
		return false;
	}
};

int main() {
	int n;
	cin >> n;
	cin.ignore();
	sapxep s[100];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if ((s[i] < s[j])==true || s[i]==s[j]) {
				sapxep tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}

		}
	}
	for (int i = 0; i < n; i++) {
		cout << s[i];
	}
	return 0;
}