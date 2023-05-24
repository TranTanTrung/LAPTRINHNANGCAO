#include<iostream>

using namespace std;

int a[4] = { -1,1,0,0 }, b[4] = { 0,0,-1,1 }, n, m, x, y, danhDau[105][105], dem = 0;

void nhap() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> danhDau[i][j];
		}
	}
}

void backtracking(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int u = y + a[i];
		int v = x + b[i];
		if (u >= 0 && u < n && v >= 0 && v < m && danhDau[u][v] == 0) {
			dem++;
			danhDau[u][v] = 1;
			backtracking(u, v);
		}
	}
}


int main() {
	cin >> n >> m >> y >> x;
	nhap();
	if (danhDau[y - 1][x - 1] == 0) {
		danhDau[y - 1][x - 1] = 1;
		dem++;
	}
	backtracking(y - 1, x - 1);
	cout << dem;
}