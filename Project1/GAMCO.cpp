#include <iostream>

using namespace std;

char a[100][100]; 

bool danhdau[100][100];//false chưa đi qua, true đã đi qua

int xc, yc;//tọa độ con bò
int xb, yb;//tọa độ chuồng bò

int n, m;//n dòng, m cột

//4 hướng di chuyển
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };

int so_o_da_di_qua = 0; //Số ô đã đi qua
int imin;

//Xét tại vị trí x, y
void _Try(int x, int y);

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			if (a[i][j] == 'C') {//tọa độ xuất phát - tọa độ con bò
				xc = i;
				yc = j;
			}
			if (a[i][j] == 'B') {//tọa độ kết thúc - tọa độ chuồng bò
				xb = i;
				yb = j;
			}
		}
	}
	//Đi từ ô xuất phát xc, yc
	so_o_da_di_qua = 1;
	danhdau[xc][yc] = true;

	imin = n * m;

	_Try(xc, yc); //vị trí xuất phát

	cout << imin - 1;
	return 0;
}
void _Try(int x, int y) {
	if (x == xb && y == yb) {
		if (so_o_da_di_qua < imin) {
			imin = so_o_da_di_qua;
		}
	}
	else {
		for (int i = 0; i < 4; ++i) {
			int xmoi = x + dx[i];
			int ymoi = y + dy[i];
			if (0 <= xmoi && xmoi < n && 0 <= ymoi && ymoi < m //nằm trong bảng đồ
				&& danhdau[xmoi][ymoi] == false
				&& a[xmoi][ymoi] != '*') {
				//Thử
				danhdau[xmoi][ymoi] = true;
				so_o_da_di_qua ++;

				_Try(xmoi, ymoi);

				//Quay lui
				so_o_da_di_qua --;
				danhdau[xmoi][ymoi] = false;
			}
		}
	}
}