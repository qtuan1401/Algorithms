#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    long long n;
    cin >> n;
    n *= 2;
    for (long long i = 1; i * i <= n; i++) {
        long long x = i * (i + 1);
        long long y = n - x;
        if (y <= 1)
            continue;
        long long z = sqrt(y);
        if (z * (z + 1) == y) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}