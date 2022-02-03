#include <bits/stdc++.h>

using namespace std;

int a1, a2, k1, k2, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    cout << max(0, n - a1 * (k1 - 1) - a2 * (k2 - 1)) << " ";
    if (k1 > k2) {
        swap(k1, k2);
        swap(a1, a2);
    }
    int m = n;
    n -= a1 * k1;
    if (n > 0)
        n = a1 + (n / k2);
    else n = m / k1;
    cout << n;
    return 0;
}