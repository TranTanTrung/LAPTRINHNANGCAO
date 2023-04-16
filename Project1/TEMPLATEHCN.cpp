#include <iostream>

using namespace std;

class hcn {
	int a, b;
public:
	hcn(int _a = 0, int _b = 0) {
		a = _a;
		b = _b;
	}
	hcn(const hcn& h) {
		a = h.a;
		b = h.b;
	}
	~hcn() {};
	friend istream
};

int main() {

	return 0;
}