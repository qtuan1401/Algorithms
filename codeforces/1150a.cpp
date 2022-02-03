#include <bits/stdc++.h>

using namespace std;

long long n, m, r, mn = 1e15, mx = -1e15, x;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        mn = min(mn, x);
    }

    for(int i = 1; i <= m; i++) {
        cin >> x;
        mx = max(mx, x);
    }
    if (mx > mn) {
        //cout << r / mn << " ";
        r = r % mn + r / mn * mx; 
    } 
    cout << r;
    return 0;
}