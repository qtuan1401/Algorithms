#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

int n, mx, f[MXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        f[x] = f[x - 1] + 1;
        mx = max(mx, f[x]);
    }
    cout << n - mx;
    return 0;
}