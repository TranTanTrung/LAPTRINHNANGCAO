#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
	string s;
	cin >> s;
	queue<char> q;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'u' || s[i] == 'p' || s[i] == 'c' || s[i] == 'o' || s[i] == 'd' || s[i] == 'e' || s[i] == 'r') {
			q.push(s[i]);
		}
	}
	string s1;
	while (!q.empty()) {
		if (q.front() == 'u') {
			s1 = s1 + q.front();
			q.pop();
			break;
		}
		else {
			q.pop();
		}
	}
	while (!q.empty()) {
		if (q.front() == 'p') {
			s1 = s1 + q.front();
			q.pop();
			break;
		}
		else {
			q.pop();
		}
	}
	while (!q.empty()) {
		if (q.front() == 'c') {
			s1 = s1 + q.front();
			q.pop();
			break;
		}
		else {
			q.pop();
		}
	}
	while (!q.empty()) {
		if (q.front() == 'o') {
			s1 = s1 + q.front();
			q.pop();
			break;
		}
		else {
			q.pop();
		}
	}
	while (!q.empty()) {
		if (q.front() == 'd') {
			s1 = s1 + q.front();
			q.pop();
			break;
		}
		else {
			q.pop();
		}
	}
	while (!q.empty()) {
		if (q.front() == 'e') {
			s1 = s1 + q.front();
			q.pop();
			break;
		}
		else {
			q.pop();
		}
	}
	while (!q.empty()) {
		if (q.front() == 'r') {
			s1 = s1 + q.front();
			q.pop();
			break;
		}
		else {
			q.pop();
		}
	}
	if (s1 == "upcoder") {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}