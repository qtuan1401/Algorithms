#include <bits/stdc++.h>

using namespace std;

const int MXN = 2e5 + 10;

int n, res, k;
int a[MXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        res += a[i];
    }

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] -= x;
    }

    sort(a, a + n, greater < int > ());
    int ans = res;
    //cout << res << endl;
    //for(int i = 0; i < n; i++)
    //    cout << a[i] << " ";
    //int ans = res;
    for(int i = 0; i < n - k; i++) {
        res -= a[i];
        ans = min(ans, res);
    }
    cout << ans;
    return 0;
}