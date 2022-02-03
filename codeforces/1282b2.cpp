#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, p, k;
        cin >> n >> p >> k;
        vector < int > a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        int res = -1;
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++) {
            //cout << a[i] << " * ";
            if (i < k - 1)
                a[i] += a[i - 1];
            else if (i >= k)
                a[i] += a[i - k];
            if (a[i] <= p)
                res = i;
        }
        cout << res + 1 << '\n';
    }
    return 0;
}