#include <iostream>
#include <stack>
#include <string>
using namespace std;

int xuly(stack<int> mystack) {
	string s;
	while (cin >> s) {
		if (s == "+" || s == "-" || s == "*") {
			int b = mystack.top(); mystack.pop();
			int a = mystack.top(); mystack.pop();
			if (s == "+") {
				mystack.push(a + b);
			}
			if (s == "-") {
				mystack.push(a - b);
			}
			if (s == "*") {
				mystack.push(a * b);
			}
		}
		else {
			mystack.push(stoi(s));
		}
	}
	return mystack.top();
}

int main() {
	stack<int> mystack;
	
	cout << xuly(mystack);
	return 0;
}