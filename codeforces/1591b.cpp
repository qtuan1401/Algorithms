#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("test.in", "r", stdin);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < int > a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        
        int res = 0, cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (cur < a[i]) {
                cur = a[i];
                res++;
            }
        }
        cout << res - 1 << '\n';
    }
    return 0;
}