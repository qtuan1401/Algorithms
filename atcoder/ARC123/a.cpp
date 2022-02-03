#include <bits/stdc++.h>

using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;
    if (b - a == c - b) {
        cout << 0;
    } else if (b > a && b > c) {
        cout << 2 * b - (a + c);
    } else {
        long long x = max(a, c);
        long long y = min(a, c);
        if (x - b < b - y) {
            cout << b - y - (x - b);
        } else {
            long long z = x - y;
            cout << y + (z + 1) / 2 - b + (z % 2);
        }
    }
    return 0;
}