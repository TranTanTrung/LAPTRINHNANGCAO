#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<char> q;
	char s;
	while (cin >> s) {
		if (s != '*') {
			q.push(s);
		}
		else {
			if (!q.empty()) {
				cout << q.front();
				q.pop();
			}
		}
	}
	return 0;
}