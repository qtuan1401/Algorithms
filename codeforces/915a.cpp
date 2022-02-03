#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, k, res = 1e9;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (k % x == 0)
            res = min(res, k / x);
    }
    cout << res;
    return 0;
}