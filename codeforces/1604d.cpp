#include <bits/stdc++.h>

using namespace std;

// long long calc(long long a, long long b, long long x, long long y) {
//     long long n = a * x + (y % x) / (b + 1);
//     if (n % x == y % n) return n;
//     return -1;
// }

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--) {
        long long x, y;
        cin >> x >> y;
        long long k = y % x;
        long long temp = (y - k) / x;
        if (temp == 0) {
            cout << y * (x + 1) << '\n';
        } else {
            cout << temp * x + k / 2 << '\n';
        }
    }
    return 0;
}