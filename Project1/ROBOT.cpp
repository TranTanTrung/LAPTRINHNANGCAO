#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#define MAX 101
#define lli long long int

using namespace std;
//ifstream is("robot.inp");
//ofstream os("robot.out");

void Try(int i, int j);

lli binToDec(string s);

int n, a[MAX][MAX];
int dong[] = { 1, 0 };
int cot[] = { 0, 1 };

string ddi, Max;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	//is.close();

	ddi += a[0][0] + 48;
	Max = "";

	Try(0, 0);

	cout << binToDec(Max) << endl;

	//os.close();
	return 0;
}

void Try(int i, int j) {
	if (i == n - 1 && j == n - 1) {
		if (ddi > Max)
			Max = ddi;
	}
	else {
		for (int k = 0; k <= 1; k++) {
			int ii = i + dong[k];;
			int jj = j + cot[k];
			if (0 <= ii && ii < n && 0 <= jj && jj < n) {
				ddi += a[ii][jj] + 48;

				Try(ii, jj);

				ddi.erase(ddi.size() - 1, 1);
			}
		}
	}
}
lli binToDec(string s) {
	lli kq = 0;
	int n = s.length(), dem = n - 1;
	for (int i = 0; i < n; i++) {
		kq += (s[i] - 48) * (lli)pow(2, dem--);
	}

	return kq;
}