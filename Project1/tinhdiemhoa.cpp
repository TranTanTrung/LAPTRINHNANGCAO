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