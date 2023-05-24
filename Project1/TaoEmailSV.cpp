#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

string capital(string hoten) {
    for (int i = 0; i < hoten.length(); ++i) {
        hoten[i] = tolower(hoten[i]);
    }
    vector<string> vctr;
    stringstream cc(hoten);
    string tk;
    while (cc >> tk) {
        vctr.push_back(tk);
    }
    hoten = "";
    hoten += vctr[vctr.size() - 1];
    for (int k = 0; k < vctr.size() - 1; ++k) {
        hoten += (vctr[k])[0];
    }
    return hoten;
}

int main() {

    int k;

    string hoten[100];

    cin >> k;

    cin.ignore();

    for (int i = 0; i < k; ++i) {

        getline(cin, hoten[i]);

        hoten[i] = capital(hoten[i]);
    }

    map<string, int> m;

    for (int i = 0; i < k; ++i) {

        m[hoten[i]]++;

        cout << hoten[i];

        if (m[hoten[i]] != 1)

            cout << m[hoten[i]];

        cout << "@gmail.com";

        if (i < k - 1) cout << endl;
    }

    return 0;
}