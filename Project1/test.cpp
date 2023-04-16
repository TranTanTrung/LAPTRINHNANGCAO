#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int a, b;

	ifstream ifile("input.txt");
	ofstream ofile("output.txt");

	ifile >> a >> b;
	ofile << a + b;

	ifile.close();
	ofile.close();
	return 0;
}