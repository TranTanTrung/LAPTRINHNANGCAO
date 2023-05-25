#include <iostream>
#include <string>
using namespace std;

void nhap(string s, float tl, int a, int b, int c) { //tl là trọng lượng, a là ngày, b là tháng, c là năm
	getline(cin, s);
	cin >> tl >> a >> b >> c;
}
void xuat(string s, float tl, int a, int b, int c) {
	cout << s << endl;
	cout << tl << endl;
	cout << a << "/" << b << "/" << c;
}

int main() {
	string s;
	float tl;
	int a, b, c;
	getline(cin, s);
	cin >> tl >> a >> b >> c;
	xuat(s, tl, a, b, c);
	return 0;
}
