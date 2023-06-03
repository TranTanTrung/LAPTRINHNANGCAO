// Đệ quy
#include <iostream>

using namespace std;

int doi_co_so(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    else {
        return doi_co_so(n / 2) * 10 + n % 2;
    }
}

int main() {
    int n;
    cin >> n;
    cout << doi_co_so(n);
    return 0;
}


// STACK
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