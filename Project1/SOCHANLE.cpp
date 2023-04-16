#include <iostream>
#include <vector>
using namespace std;

class sochan {
	int n;
public:
	sochan(int _n = 0) {
		n = _n;
	}
	sochan(const sochan& s) {
		n = s.n;
	}
	~sochan() {};
	int getn() {
		return n;
	}
	friend istream& operator >> (istream& is, sochan& s) {
		is >> s.n;
		return is;
	}
	friend ostream& operator << (ostream& os, sochan& s) {
		os << s.layso();
		return os;
	}
	int dem() {
		int dem = 0;
		while (n > 0) {
			dem++;
			n /= 10;
		}
		return dem;
	}
	int layso() {
		sochan s1;
		s1.n = n;
		int tong = 0;
		vector<int> v;
		while (s1.n > 0) {
			int z = s1.n % 10;
			v.push_back(z);
			s1.n = s1.n / 10;
		}
		for (int i = s1.dem() - 1; i >= 0; i--) {
			tong = tong * 10 + v[i];
		}
		return tong;
	}
	int laysole() {
		sochan s1;
		s1.n = n;
		int tong = 0;
		vector<int> v;
		while (s1.n > 0) {
			v.push_back(s1.n % 10);
			s1.n = s1.n / 10;
		}
		if (s1.n < 9999) {
			for (int i = v.size() - 1; i >= 0; i--) {
				if (i % 2 == 0) {
					tong = tong * 10 + v[i];
				}
			}
		}
		else {
			for (int i = v.size() - 1; i >= 0; i--) {
				if (i % 2 != 0) {
					tong = tong * 10 + v[i];
				}
			}
		}
		return tong;
	}
	bool operator < (sochan& s) {
		if (layso() < s.layso()) {
			return true;
		}
		return false;
	}
};
void tongthanhphan(sochan &s, int x) {
	sochan s1, s2;
	s1 = s;
	s2 = s;
	int tong = 0;
	if (x%2==0) {
		int z = s1.layso();
		while (z > 0) {
			tong = tong + z % 10;
			z = z / 10;
		}
	}
	else {
		int z = s2.laysole();
		while (z > 0) {
			tong = tong + z % 10;
			z = z / 10;
		}
	}
	cout << tong << endl;
}

int main() {
	/*sochan s1, s2;
	cin >> s1 >> s2;
	int n;
	cin >> n;
	cout << s1 << endl;
	cout << s2 << endl;
	if (s1 < s2) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	tongthanhphan(s1, n);	
	tongthanhphan(s2, n);*/
	sochan s;
	cin >> s;
	cout << s;
	return 0;
}