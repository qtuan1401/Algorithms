#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5 + 10;

int n;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    a[n] = 1e6;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int res = (1000000 - a[0]);
    for(int i = 0; i < n; i++)
        res = min(res, max(a[i] - 1, 1000000 - a[i + 1]));
    cout << res;
    return 0;
}