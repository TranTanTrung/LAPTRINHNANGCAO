#include <iostream>

using namespace std;

class dh {
	int n, a[100], z , t[100];
public:
	dh(int _n = 0, int _z=0) {
		n = _n;
		z = _z;
	}
	dh(const dh& d) {
		n = d.n;
		z = d.z;
	}
	~dh() {};
	friend istream& operator >> (istream& is, dh& d) {
		is >> d.n;
		for (int i = 0; i <= d.n; i++) {
			cin >> d.t[i];
		}
		int x = d.n;
		d.a[d.z] = x;
		d.z++;
		while (x > 0) {
			d.a[d.z] = x - 1;
			x = x - 1;
			d.z++;
		}
		return is;
	}
	friend ostream& operator << (ostream& os, dh& d) {
		for (int i = 0; i <= d.n; i++) {
			if (d.t[i] == 0) {
				for (int j = i; j <= d.n; j++) {
					d.t[j] = d.t[j + 1];
					d.a[j] = d.a[j + 1];
				}
				d.n--;
			}
		}
		if (d.a[0] == 1) {
			os << d.t[0] << "x";
		}
		else if (d.a[0] == 0) {
			os << d.t[0];
		}
		else {
			os << d.t[0] << "x^" << d.a[0];
		}
		for (int i = 1; i <= d.n; i++) {
			if (d.t[i] < 0) {
				if (d.a[i] == 1) {
					if (d.t[i] == -1) {
						os << "-x";
					}
					else {
						os << d.t[i] << "x";
					}
				}
				else if (d.a[i] == 0) {
					os << d.t[i];
				}
				else {
					if (d.t[i] == -1) {
						os << "-x^" << d.a[i];
					}
					else {
						os << d.t[i] << "x^" << d.a[i];
					}
				}
			}
			else {
				if (d.a[i] == 1) {
					if (d.t[i] == 1) {
						os << "+x";
					}
					else {
						os << "+" << d.t[i] << "x";
					}
				}
				else if (d.a[i] == 0) {
					os << "+" << d.t[i];
				}
				else {
					if (d.a[i] == 1) {
						os << "+" << "x^" << d.a[i];
					}
					else {
						os << "+" << d.t[i] << "x^" << d.a[i];
					}
				}
			}
		}
		return os;
	}
	dh cap1() {
		dh kq;
		for (int i = 0; i <= n; i++) {
			kq.t[i] = t[i] * a[i];
			kq.a[i] = a[i] - 1;
			kq.n++;
		}
		return kq;
	}
};

int main() {
	dh h;
	cin >> h;
	cout << h << endl;
	dh h1 = h.cap1();
	cout << h1 << endl;
	dh h2 = h1.cap1();
	cout << h2;
	return 0;
}