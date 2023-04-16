#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream ofile("output.txt");

	int a, b;
	cin >> a >> b;
	ofile << a + b;

	ofile.close();
	return 0;
}