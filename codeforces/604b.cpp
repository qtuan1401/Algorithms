#include <bits/stdc++.h>

using namespace std;
 
const int MXN = 1e5 + 10;

int res, n, k;
int a[MXN];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        res = max(res, a[i]);
    }
    for(int i = 0; i < n - k; i++)
        res = max(res, a[i] + a[2 * (n - k) - 1 - i]);
    cout << res;
    return 0;
}