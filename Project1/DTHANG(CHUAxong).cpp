#include <iostream>

using namespace std;

class dt {
	int a, b, c;
public:
	friend istream& operator >> (istream& is, dt& d) {
		is >> d.a >> d.b >> d.c;
		return is;
	}
	friend ostream& operator << (ostream& os, dt& d) {
		if (d.a == 1) {
			os << "x ";
		}
		else if (d.a == -1) {
			os << "-x ";
		}
		else {
			os << d.a << "x ";
		}
		if (d.b < 0) {
			if (d.b == -1) {
				os << "- " << "y ";
			}
			else {
				os << "- " << d.b * -1 << "y ";
			}
		}
		else {
			os << "+ " << d.b << "y ";
		}
		if (d.c < 0) {
			os << "- " << d.c * -1;
		}
		else {
			os << "+ " << d.c;
		}
		cout << " = 0" << endl;
		return os;
	}
	bool operator == (dt& d) {
		if (a == d.a && b == d.b) {
			return true;
		}
		return false;
	}
	int tinhD(dt& d) {
		return a * d.b - d.a * b;
	}
	int tinhDX(dt& d) {
		return d.c * b - c * d.b;
	}
	int tinhDY(dt& d) {
		return d.a * c - a * d.c;
	}
	void xuatvitri(dt& d) {
		if (tinhD(d) != 0) {
			cout << "C" << endl;
		}
		else if (tinhD(d) == 0 && tinhDX(d) == 0 && tinhDY(d) == 0) {
			cout << "T" << endl;
		}
		else if (tinhD(d) == 0 && tinhDX(d) != 0 && tinhDY(d) != 0) {
			cout << "S" << endl;
		}
		else {
			cout << "V" << endl;
		}
	}
};

int main() {
	dt d1, d2;
	cin >> d1 >> d2;
	cout << d1 << d2;
	d1.xuatvitri(d2);
	return 0;
}