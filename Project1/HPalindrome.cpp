#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <algorithm>

using namespace std;

string xoakhoangtrang(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			s.erase(s.begin() + i);
			i--;
		}
	}
	return s;
}
string chuyenthuongthanhhoa(string s) {
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] = s[i] - 32;
		}
	}
	return s;
}
string doixung(string s) {
	reverse(s.begin(), s.end());
	return s;
}

int main() {
	ifstream ifile("input.txt");
	ofstream ofile("output.txt");

	string s;
	while (getline(ifile, s)) {
		if (xoakhoangtrang(chuyenthuongthanhhoa(s)) == doixung(xoakhoangtrang(chuyenthuongthanhhoa(s)))) {
			ofile << "1" << endl;
		}
		else {
			ofile << "0" << endl;
		}
	}

	ifile.close();
	ofile.close();
	return 0;
}