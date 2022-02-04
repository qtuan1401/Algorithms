#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

long long calc(int x) {
    return 1ll * x * (x + 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector < int > k(n + 1, 0), h(n + 1, 0);
        vector < long long > f(n + 1, INF);
        for (int i = 1; i <= n; i++)
            cin >> k[i];
        for (int i = 1; i <= n; i++)
            cin >> h[i];
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            int p = 1e9 + 7;
            for (int j = i; j >= 1; j--) {
                p = min(p, k[j] - h[j] + 1);
                if (p <= k[j - 1]) continue;
                f[i] = min(f[i], f[j - 1] + calc(k[i] - p + 1));
            }
        }
        cout << f[n] << '\n';
    }
    
    return 0;
}