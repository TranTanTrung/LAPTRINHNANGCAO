#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int kiemtra(int n) {
	if (n < 2) {
		return false;
	}
	if (n == 2) {
		return true;
	}
	if (n % 2 == 0) {
		return false;
	}
	else {
		for (int i = 2; i <= sqrt(n); i++) {
			if (n % i == 0) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ifstream ifile("input.txt");
	ofstream ofile("output.txt");

	int n;
	ifile >> n;
	int a[100];
	for (int i = 0; i < n; i++) {
		ifile >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (kiemtra(a[i]) == true) {
			ofile << a[i] << endl;
		}
		else {
			ofile << "-1" << endl;
		}
	}
	return 0;
}