#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#define MAX 101
#define lli long long int

using namespace std;
//ifstream is("robot2.inp");
//ofstream os("robot2.out");

void Try(int i, int j);

lli binToDec(string s);

int n, a[MAX][MAX], vt_dong, vt_cot;
int dong[] = { 1, 0 };
int cot[] = { 0, 1 };

string ddi, Min;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	//is.close();

	ddi += a[0][0] + 48;

	for (int i = 0; i < n * n; i++) {
		Min += "1";
	}

	Try(0, 0);

	cout << binToDec(Min) << endl;

	//os.close();
	return 0;
}

void Try(int i, int j) {
	if (i == n - 1 && j == n - 1) {
		if (ddi < Min)
			Min = ddi;
	}
	else {
		for (int k = 0; k <= 1; k++) {
			int ii = i + dong[k];;
			int jj = j + cot[k];
			if (0 <= ii && ii < n && 0 <= jj && jj < n) {
				if (a[ii][jj] != -1) {
					ddi += a[ii][jj] + 48;

					Try(ii, jj);

					ddi.erase(ddi.size() - 1, 1);
				}
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