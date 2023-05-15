#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	stack<int> s;
	while (n > 0) {
		if (n % 2 == 0) {
			s.push(0);
		}
		if (n % 2 != 0) {
			s.push(1);
		}
		n = n / 2;
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	return 0;
}