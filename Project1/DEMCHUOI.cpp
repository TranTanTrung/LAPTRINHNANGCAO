#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();
	string s, s1;
	getline(cin, s);
	while (n > 0) {
		int dem = 0;
		getline(cin, s1);
		int k = s1.size();
		for (int i = 0; i < k; i++) {
			long long z = s1.find(s);
			if (z > s1.size()) {
				break;
			}
			s1.erase(s1.begin() + 0, s1.begin() + z + 1);
			cout << s1 << endl;
			if (k > s1.size()) {
				dem++;
			}
		}
		cout << dem << endl;
		n--;
	}
	return 0;
}