#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    vector < int > a(n);
    cin >> n;
    int res = 1e3;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0 || i == n - 1) {
            res = min(res, a[i]);
        } else {
            res = min(res, max(a[i - 1], a[i]));
        }
    }
    cout << res;
    return 0;
}