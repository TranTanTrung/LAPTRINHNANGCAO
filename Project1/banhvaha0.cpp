#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		cin.ignore();
		queue<char> q;
		for (int y = 0; y < s.size(); y++) {
			q.push(s[y]);
		}
		int b[100];
		int tmp = 0;
		int hieu = (int)q.front() - 48;
		q.pop();
		while (!q.empty()) {
			char a = q.front();
			int x = (int)q.front() - 48;
			if (a != '-') {
				hieu = hieu * 10 + x;
				q.pop();
				if (q.empty()) {
					b[tmp] = hieu;
					tmp++;
					break;
				}
			}
			else {
				b[tmp] = hieu;
				tmp++;
				q.pop();
				hieu = (int)q.front() - 48;
				q.pop();
			}
			if (q.empty()) {
				b[tmp] = hieu;
				tmp++;
			}
		}
		int hieu1 = b[0];
		for (int y = 1; y < tmp; y++) {
			hieu1 -= b[y];
		}
		cout << hieu1 << endl;
	}
	return 0;
}