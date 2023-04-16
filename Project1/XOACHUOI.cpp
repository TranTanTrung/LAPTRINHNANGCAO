/*Ở bài này chúng ta chỉ cần duyệt vòng lặp xem
từng kí tự của chuỗi x có xuất hiện trong chuỗi y hay không
,mà không cần biết thứ tự của chúng trong chuỗi y
,số lượng kí tự xóa của chuỗi y là độ dài y-x;*/
#include <iostream>
#include <string>

using namespace std;

int main() {
	string x, y;
	getline(cin, x);
	getline(cin, y);
	int dem1 = 0;
	for (int i = 0; i < x.size(); i++) {
		for (int j = i; j < y.size(); j++) {
			if (y[j] == x[i]) {
				dem1++;
				break;
			}
		}
	}
	if (dem1 == x.size()) {
		cout << "YES" << endl;
		cout << y.size() - x.size();
	}
	else {
		cout << "NO";
	}
	return 0;
}