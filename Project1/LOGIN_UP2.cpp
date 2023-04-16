#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool kiemtra(char a, string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s.find(a) < s.size()) {
			return true;
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	cin.ignore();
	string s;
	int a[100], x = 1, k = 0;
	while (n > 0) {
		getline(cin, s);
		if (kiemtra('u', s) == true) {
			s.erase(s.begin() + 0, s.begin() + s.find('u'));
			if (kiemtra('p', s) == true) {
				s.erase(s.begin() + 0, s.begin() + s.find('p'));
				if (kiemtra('c', s) == true) {
					s.erase(s.begin() + 0, s.begin() + s.find('c'));
					if (kiemtra('o', s) == true) {
						s.erase(s.begin() + 0, s.begin() + s.find('o'));
						if (kiemtra('d', s) == true) {
							s.erase(s.begin() + 0, s.begin() + s.find('d'));
							if (kiemtra('e', s) == true) {
								s.erase(s.begin() + 0, s.begin() + s.find('e'));
								if (kiemtra('r', s) == true) {
									a[k] = x;
									k++;
								}
							}
						}
					}
				}
			}
		}
		x++;
		n--;
	}
	cout << k << endl;
	sort(a, a + k);
	for (int i = 0; i < k; i++) {
		cout << a[i] << " ";
	}
	return 0;
}