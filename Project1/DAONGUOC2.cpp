#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int daonguoc(string s) {
	int a = 0;
	char c[100];
	for (int i = 0; i < s.size(); i++) {
		c[i] = s[i];
	}
	for (int i = s.size() - 1; i >= 0; i--) {
		a = a * 10 + int(c[i] - 48);
	}
	return a;
}
int dn(int n) {
	int a = 0;
	while (n > 0) {
		a = a * 10 + n % 10;
		n = n / 10;
	}
	return a;
}

int main() {
	ifstream ifile("inDaoNguoc2.txt");
	ofstream ofile("outDaoNguoc2.txt");

	string s;
	int max = -9999999;
	int v[100], i = 0;
	while (ifile >> s) {
		ifile.ignore();
		if (daonguoc(s) > max) {
			max = daonguoc(s);
		}
		v[i] = stoi(s);
		i++;
	}
	int dem = 0;
	ofile << dn(max) << endl;
	for (int y = 0; y < i; y++) {
		if (v[y] == dn(max)) {
			dem++;
		}
	}
	if (dem > 1) {
		for (int y = 0; y < i; y++) {
			if (v[y] == dn(max)) {
				ofile << y << " ";
			}
		}
	}

	ifile.close();
	ofile.close();
	return 0;
}