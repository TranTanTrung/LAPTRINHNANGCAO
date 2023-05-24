#include <iostream>

using namespace std;

int main() {
    int a, N;
    cin >> a >> N;
    int ans = 1;
    for (int i = 1; i <= N; ++i) {
        ans *= a;
        ans %= 10;
    }
    cout << ans;
    return 0;
}